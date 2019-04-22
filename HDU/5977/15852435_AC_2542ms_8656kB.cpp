# include <iostream>
# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <math.h>
# include <queue>
# include <string>
# include <vector>
# include <set>
# include <map>
# define INF 0x3f3f3f3f
# define Inf 0x7f7f7f7f
# define clr0(x) memset(x,0,sizeof(x))
# define clr1(x) memset(x,INF,sizeof(x))
# define clrf(x) memset(x,-1,sizeof(x))
# define rep(i,a) for(int i = 0;i<(a);i++)
# define repf(i,a,b) for(int i = (a);i<=(b);i++)
# define repu(i,a,b) for(int i = (a);i<(b);i++)
# define repd(i,a,b) for(int i = (a);i>=(b);i--)
# define lowbit x&(-x)
# define ww(a) while(a)
# define sc(x) scanf("%d",&(x))
# define sl(x) scanf("%I64d",&(x))
# define pc(x) printf("%d\n",(x));
# define pl(x) printf("%I64d\n",(x));
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define scf scanf
# define prf printf
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 50020
# define maxm 20020


using namespace std;

int n,k,cnt,ct;
bool vis[maxn];
int head[maxn];
int root,sum;
int sz[maxn];//每个点下面的大小
int f[maxn];//以每个点为根时最大子树的大小
int dep[maxn];//距离
int o[maxn];
ll ans;
int a[maxn];
int num[1050];
struct Edge{
    int to,len,next;
}edge[maxn<<1];

void init()
{
    clr0(vis);
	clr0(num);
    clrf(head);
    ans = cnt = 0;
    ct = 0;
}
void addedge(int u,int v,int w)
{
    edge[cnt].to = v;
    edge[cnt].len = w;
    edge[cnt].next = head[u];
    head[u] = cnt ++;
}

void getrt(int u,int fa)
{
    sz[u] = 1;f[u] = 0;
    for(int i = head[u];~i;i = edge[i].next){
        int to = edge[i].to;
        if(to == fa||vis[to])continue;
        getrt(to,u);
        sz[u] += sz[to];
        f[u] = max(f[u],sz[to]);
    }
    f[u] = max(f[u],sum-sz[u]);
    if(f[u]<f[root])root = u;
}

void getdep(int u,int fa,int sta)
{
	//fuck
	//cout<<sta<<endl;
    o[++ct] = sta;
	num[sta] ++;
    for(int i = head[u];~i;i = edge[i].next){
        int to = edge[i].to;
        if(to == fa||vis[to])continue;
        getdep(to,u,sta|(1<<a[to])); 
    }
}

ll cal(int u,int d0)
{
    ct = 0;clr0(num);
    getdep(u,0,d0|(1<<a[u]));
	rep(i,k){
		rep(j,(1<<k)){
			//fuck
			if(!((1<<i)&j))num[j]+=num[j|(1<<i)];//高维前缀和，求超集
		}
	}
	ll res = 0;
	repf(i,1,ct){
		int tmp = o[i];
		tmp ^= (1<<k)-1;
		res += num[tmp];
		//cout<<"Debug :"<<ct<<" "<<num[tmp]<<endl;
	}
    return res;
}

void solve(int u)
{
	vis[u] = 1;
    ans += cal(u,0);
	//vis[u] = 1;
    for(int i = head[u];~i;i = edge[i].next){
        int to = edge[i].to;
        if(vis[to])continue;
        ans -= cal(to,1<<a[u]);
        sum  = sz[to];
        //f[root=0]= sum = sz[to];
        root = 0;
        getrt(to,0);
        solve(root);
    }
}

int main()
{
    ww(~scf("%d%d",&n,&k)&&(n+k)){
        init();
		repf(i,1,n){
			sc(a[i]);
			a[i]--;
		}
        rep(i,n-1){
            int u,v,w;
            scf("%d%d",&u,&v);
            addedge(u,v,0);
            addedge(v,u,0);
        }
		ans = 0;
		root = 0;
        sum = n;
        f[0] = n;
		getrt(1,0);
		//pc(root);
		solve(root);
		pl(ans);
    }
}