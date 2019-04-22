#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define mst(x,a) memset(x,a,sizeof(x))
#define all(x) (x).begin(),(x).end()
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define cl(x) x.clear()
const int mod = 1000000007;
const int N = 100010;
void MOD(ll &a){if(a>=mod) a-=mod;}
void MOD(ll &a,ll c){if(a>=c) a-=c;}
void ADD(ll &a,ll b){ a+=b; MOD(a);}
void ADD(ll &a,ll b,ll c){a+=b;MOD(a,c);}
ll qpow(ll a,ll b){ll ans=1;while(b){if(b&1)ans=ans*a%mod;a=a*a%mod;b/=2;}return ans;}
ll qpow(ll a,ll b,ll c){ll ans=1;while(b){if(b&1)ans=ans*a%c;a=a*a%c;b/=2;}return ans;}

int tot,head[N],n;
struct EDGE{
    int to,nex;
    ll val;
}e[N*2];

ll a[N];

void addedge(int u,int v,ll x){
    e[tot].to=v;
    e[tot].val=x;
    e[tot].nex=head[u];
    head[u]=tot++;
}

int nex[N*62][2],cnt[N*62];
int root,sz;

int newnode(){
    nex[sz][0]=nex[sz][1]=cnt[sz]=0;
    return sz++;
}

void Insert(ll x){
    int now=root;
    cnt[now]++;
    for(int i=61;i>=0;i--){
        if(x&(1ll<<i)){
            if(!nex[now][1]) nex[now][1]=newnode();
            now=nex[now][1];
        }
        else{
            if(!nex[now][0]) nex[now][0]=newnode();
            now=nex[now][0];
        }
        cnt[now]++;
    }
}

ll query(ll x,int k){
    int now=root;
    ll res=0;
    for(int i=61;i>=0;i--){
        if(x&(1ll<<i)){
            if(nex[now][0]&&cnt[nex[now][0]]>=k){
                res+=(1ll<<i);
                now=nex[now][0];
            }
            else{
                if(nex[now][0]) k-=cnt[nex[now][0]];
                now=nex[now][1];
            }
        }
        else{
            if(nex[now][1]&&cnt[nex[now][1]]>=k){
                res+=(1ll<<i);
                now=nex[now][1];
            }
            else{
                if(nex[now][1]) k-=cnt[nex[now][1]];
                now=nex[now][0];
            }
        }
    }
    return res;
}

void dfs(int now,int fa,ll tmp){
    a[now]=tmp;
    for(int i=head[now];i!=-1;i=e[i].nex){
        if(e[i].to==fa) continue;
        dfs(e[i].to,now,tmp^e[i].val);
    }
}

struct si{
    ll val,ori,k;
    bool operator < (const si& shr) const{
        return val<shr.val;
    }
};

priority_queue<si> pq;
ll fin[N*2];

void init(){
    while(!pq.empty()) pq.pop();
    sz=0;
    root=newnode();
    tot=0;
    mst(head,-1);
}
int qus[N];
int main(){
    while(scanf("%d",&n)&&n){
        init();
        for(int i=1;i<n;i++){
            int u,v; ll x;
            scanf("%d%d%lld",&u,&v,&x);
            addedge(u,v,x); addedge(v,u,x);
        }
        dfs(1,1,0);
        for(int i=1;i<=n;i++) Insert(a[i]);

        for(int i=1;i<=n;i++){
            ll x=query(a[i],1);
            pq.push({x,a[i],1});
        }
        int m; scanf("%d",&m);
        int mx=1;
        for(int i=0;i<m;i++){
            scanf("%d",&qus[i]);
            mx=max(mx,qus[i]);
        }
        for(int i=1;i<=mx;i++){
            if(pq.empty()) break;
            si x=pq.top();
            fin[i]=x.val;
            pq.pop();
            x.k++;
            if(x.k<n){
                x.val=query(x.ori,x.k);
                pq.push(x);
            }
        }
        for(int i=0;i<m;i++){
            if(qus[i]>1ll*n*(n-1))
                printf("-1\n");
            else printf("%lld\n",fin[qus[i]]);
        }
    }
}
