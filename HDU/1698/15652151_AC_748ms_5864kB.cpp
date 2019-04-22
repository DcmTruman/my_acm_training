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
# define Lson(x) (x)<<1
# define Rson(x) (x)<<1|1
# define fuckio() ios::sync_with_stdio(false)
# define fuck() cout<<"fuck:"<<__LINE__<<endl

typedef long long ll;
const int maxn = 100020;
using namespace std;
int T,aa,bb,cc;
int n,m;
char c;
struct node
{
    int l,r,lazy,sum;
    void update(int k){
        sum = (r-l+1)*k;
        lazy = k;
    }
}tree[maxn*4];

void pushdown(int x)
{
    int la = tree[x].lazy;
    if(la){
        tree[Lson(x)].update(la);
        tree[Rson(x)].update(la);
        tree[x].lazy = 0;
    }
}

void pushup(int x)
{
    tree[x].sum = tree[Lson(x)].sum+tree[Rson(x)].sum;

}

void build(int x,int l,int r)
{
    tree[x].l = l;tree[x].r = r;
    tree[x].lazy = 0;
    //tree[x].sum = 1;
    if(l == r){
        tree[x].sum = 1;
        return;
    }
    int mid = (l+r)/2;
    build(Lson(x),l,mid);
    build(Rson(x),mid+1,r);
    pushup(x);
}

void update(int x,int l,int r,int v)
{
    int L = tree[x].l;int R = tree[x].r;
    if(l<=L&&R<=r){
        //cout<<L<<" "<<R<<endl;
        tree[x].update(v);
        return;
    }
    pushdown(x);
    int mid = (L+R)/2;
    if(mid>=l)update(Lson(x),l,r,v);
    if(r>mid)update(Rson(x),l,r,v);
    pushup(x);
}

int query(int x,int l,int r)
{
    int L = tree[x].l;int R = tree[x].r;
    if(l<=L&&R<=r){
        //cout<<tree[x].sum<<endl;
        return tree[x].sum;
    }
    pushdown(x);
    int mid = (L+R)/2;
    int ans = 0;
    if(mid>=l)ans += query(Lson(x),l,r);
    if(r>mid)ans += query(Rson(x),l,r);
    return ans;
}

int main()
{
    fuckio();
    scanf("%d",&T);
    repf(tt,1,T){
        scanf("%d",&n);
        build(1,1,n);
        scanf("%d",&m);
        W(m--){
            scanf("%d%d%d",&aa,&bb,&cc);
            update(1,aa,bb,cc);
        }
        printf("Case %d: The total value of the hook is %d.\n",tt,tree[1].sum);
    }
}