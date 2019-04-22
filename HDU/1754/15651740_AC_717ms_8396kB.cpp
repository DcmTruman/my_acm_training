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
# define ll long long
# define fuckio() ios::sync_with_stdio(false)
# define fuck() cout<<"fuck:"<<__LINE__<<endl
# define maxn 200020

using namespace std;

int m,n,a[maxn],aa,bb;
char c;
struct node
{
    int l,r,mx;
}tree[maxn<<2];

void push_up(int x)
{
     tree[x].mx = max(tree[Lson(x)].mx,tree[Rson(x)].mx);
}

void build(int x,int l,int r)
{
    tree[x].l = l;tree[x].r = r;
    tree[x].mx = 0;
    if(l==r){
        tree[x].mx = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(Lson(x),l,mid);
    build(Rson(x),mid+1,r);
    push_up(x);
}

void update(int x,int id,int val)
{
    //fuck();
    int L = tree[x].l;
    int R = tree[x].r;
    if(L == R){
        //fuck();
        tree[x].mx = val;
        return;
    }
    int mid = (L+R)/2;
    if(mid>=id)update(Lson(x),id,val);
    else if(id>mid)update(Rson(x),id,val);
    push_up(x);
}

int query(int x,int l,int r)
{
    int L = tree[x].l;
    int R = tree[x].r;
    if(l<=L&&R<=r){
        return tree[x].mx;
    }
    int mid = (L+R)/2;
    int ans = -1;
    if(mid>=l)ans = max(ans,query(Lson(x),l,r));
    if(r>mid)ans = max(ans,query(Rson(x),l,r));
    return ans;
}
int main()
{
    fuckio();
    W(cin>>n>>m){
        repf(i,1,n)cin>>a[i];
        build(1,1,n);
        W(m--){
            cin>>c>>aa>>bb;
            if(c == 'Q'){
                cout<<query(1,aa,bb)<<endl;
            }
            else if(c == 'U'){
                update(1,aa,bb);
            }
        }
    }
}