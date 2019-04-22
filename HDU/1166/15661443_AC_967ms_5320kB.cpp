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
# define fuckio(); ios::sync_with_stdio(false);
# define fuck(); cout<<"fucl:"<<__LINE__<<endl;
# define maxn 500200
using namespace std;


ll a[maxn],n,T;
struct node
{
    int l,r;
    ll sum;
    ll lazy;
    void update(ll x){
        sum += 1ll*(r-l+1)*x;
        lazy += x; 
    }
}tree[maxn*4];


void push_up(ll x)
{
    tree[x].sum = tree[Lson(x)].sum+tree[Rson(x)].sum;
}

void push_down(ll x)
{
    int la = tree[x].lazy;
    if(la){
        tree[Lson(x)].update(la);
        tree[Rson(x)].update(la);
        tree[x].lazy = 0;
    }
}

void build(int x,int l,int r)
{
    tree[x].l = l;tree[x].r = r;
    tree[x].sum = tree[x].lazy = 0;
    if(l == r){
        //cout<<a[l]<<endl;
        tree[x].sum = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(Lson(x),l,mid);
    build(Rson(x),mid+1,r);
    push_up(x);
}

void update(int x,int p,ll val)
{
    int L = tree[x].l,R = tree[x].r;
    if(L == R){
        //cout<<a[L]<<endl;
        tree[x].update(val);
        return;
    }
    push_down(x);
    int mid = (L+R)/2;
    if(mid>=p)update(Lson(x),p,val);
    else if(mid<p)update(Rson(x),p,val);
    push_up(x);
}
ll query(int x,int l,int r)
{
   // cout<<l<<" "<<r<<endl;
    int L = tree[x].l,R = tree[x].r;
    if(l<=L&&R<=r){
        //cout<<tree[x].sum<<endl;
        return tree[x].sum;
    }
    push_down(x);
    int mid = (L+R)/2;
    ll ans = 0;
    if(mid>=l)ans+= query(Lson(x),l,r);
    if(mid<r)ans += query(Rson(x),l,r);
    push_up(x);
    return ans; 
}
int main()
{
    fuckio();
    Sc(T);
    repf(tt,1,T){
        printf("Case %d:\n",tt);
        Sc(n);
        repf(i,1,n){
            Sc(a[i]);
        }
        build(1,1,n);
        string s;
        W(cin>>s){
            if(s == "Query"){
                int aa,bb;cin>>aa>>bb;
                cout<<query(1,aa,bb)<<endl;
            }
            else if(s == "Add"){
                ll aa,bb;cin>>aa>>bb;
                update(1,aa,bb); 
            }
            else if(s == "Sub"){
                ll aa,bb;cin>>aa>>bb;
                update(1,aa,-bb);
            }
            else if(s == "End")break;
        }
    }
   return 0;
}