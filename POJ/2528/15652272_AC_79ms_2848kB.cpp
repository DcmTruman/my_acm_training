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
# define clr0(x) memset(x,0,sizeof(x))
# define clr1(x) memset(x,INF,sizeof(x))
# define rep(i,a) for(int i = 0;i<(a);i++)
# define repf(i,a,b) for(int i = (a);i<=(b);i++)
# define repu(i,a,b) for(int i = (a);i<(b);i++)
# define repd(i,a,b) for(int i = (a);i>=(b);i--)
# define lowbit x&(-x)
# define W(a) while(a)
# define Sc(x) scanf("%lld",&(x))
# define Lson(x) ((x)<<1)
# define Rson(x) (((x)<<1)|1)
# define fuckio() ios::sync_with_stdio(false)
# define fuck() cout<<"fuck:"<<__LINE__<<endl

typedef long long ll;
ll ans;
const int maxn = 100200;
using namespace std;
int T,aa,bb,cc;
int n,m;
char c;
vector<int>V;
int li[maxn];
int ri[maxn];
bool visit[maxn<<4];
int getid(int x){return lower_bound(V.begin(),V.end(),x)-V.begin()+1;}

struct node
{
    int l,r,num;
}tree[maxn<<4];

struct tt{
    int l;
    int r;
}ee[maxn<<4];
void pushdown(int x)
{
    if(tree[x].num == 0)return;
    tree[Lson(x)].num = tree[Rson(x)].num = tree[x].num;
    tree[x].num = 0;
}


void build(int x,int l,int r)
{
    tree[x].l = l;tree[x].r = r;
    tree[x].num= 0;
    //tree[x].sum = 1;
    if(l == r){
        //tree[x].sum = 1;
        return;
    }
    int mid = (l+r)/2;
    build(Lson(x),l,mid);
    build(Rson(x),mid+1,r);
}

void update(int x,int l,int r,int v)
{
    int L = tree[x].l;int R = tree[x].r;
    if(l<=L&&R<=r){
        //cout<<L<<" "<<R<<endl;
        tree[x].num = v;
        return;
    }
    pushdown(x);
    int mid = (L+R)/2;
    if(mid>=l)update(Lson(x),l,r,v);
    if(r>mid)update(Rson(x),l,r,v);
    //pushup(x);
}

void query(int x,int l,int r)
{
    if(tree[x].num!=0){
        if(!visit[tree[x].num]){
            visit[tree[x].num] = true;
            ans ++;
        }
        return;
    }
    
    int mid = (l+r)/2;
    int ans = 0;
    query(Lson(x),l,mid);
    query(Rson(x),mid+1,r);
}

int main()
{
    fuckio();
    cin>>T;
    W(T--){
        V.clear();
        clr0(visit);
        scanf("%d",&n);
        repf(i,1,n){
            scanf("%d%d",&li[i],&ri[i]);
            V.push_back(li[i]);
            V.push_back(ri[i]);
        }
        sort(V.begin(),V.end());V.erase(unique(V.begin(),V.end()));
        int len = V.size();

        int R = 0;
        repf(i,1,n){
            ee[i].l = getid(li[i]);
            ee[i].r = getid(ri[i]);
            R = max(R,ee[i].r);
        }
        build(1,1,R);
        repf(i,1,n){
            update(1,ee[i].l,ee[i].r,i);
        }
        ans = 0;
        query(1,1,R);
        cout<<ans<<endl;
    }

}