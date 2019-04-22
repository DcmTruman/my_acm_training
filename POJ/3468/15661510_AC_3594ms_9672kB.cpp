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

ll m,n,aa,bb,a[maxn],cc;
ll N,Q;
char c;

struct node
{
    ll l,r,sum,lazy;
    void update(ll x){
        sum += 1ll*(r-l+1)*x;
        lazy += x;
    }
}tree[maxn<<2];

void pushup(int x)
{
    tree[x].sum = tree[Lson(x)].sum+tree[Rson(x)].sum;
}
void pushdown(ll x)
{
    ll la = tree[x].lazy;
    if(la){
        tree[Lson(x)].update(la);
        tree[Rson(x)].update(la);
        tree[x].lazy = 0;
    }
}

void build(int x,int l,int r)
{
    //fuck();
    //cout<<l<<" "<<r<<endl;
    tree[x].l = l;tree[x].r = r;
    tree[x].sum = tree[x].lazy = 0;
    if(l == r){
        //cout<<l<<" "<<a[l]<<endl;
        tree[x].sum = a[l];
        return ;
    }
    int mid = (l+r)/2;
    build(Lson(x),l,mid);
    build(Rson(x),mid+1,r);
    pushup(x);
}

void update(int x,int l,int r,ll val)
{
    int L = tree[x].l;int R = tree[x].r;
    if(l<=L&&R<=r){
        tree[x].update(val);
        return;
    }
    pushdown(x);
    int mid = (L+R)/2;
    if(mid>=l)update(Lson(x),l,r,val);
    if(r>mid)update(Rson(x),l,r,val);
    pushup(x);
}

ll query(int x,int l,int r)
{
    int L = tree[x].l;int R = tree[x].r;
    if(l<=L&&R<=r){
        return tree[x].sum;
    }
    pushdown(x);
    int mid = (L+R)/2;
    ll ans = 0;
    if(mid>=l)ans += query(Lson(x),l,r);
    if(r>mid)ans += query(Rson(x),l,r);
    return ans;
}

int main()
{
    fuckio();
    cin>>N>>Q;
    repf(i,1,N)cin>>a[i];
    build(1,1,N);
    W(Q--){
        cin>>c;
        if(c == 'Q'){
            cin>>aa>>bb;
            cout<<query(1,aa,bb)<<endl;
        }
        else if(c == 'C'){
            cin>>aa>>bb>>cc;
            update(1,aa,bb,cc);
        }
    }
return 0;
}