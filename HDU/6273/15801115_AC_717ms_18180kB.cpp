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
# define sl(x) scanf("%lld",&(x)
# define pc(x) printf("%d\n",(x));
# define pl(x) printf("%lld\n",(x));
# define scf scanf
# define prf printf
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 200020

using namespace std;

const int MOD = 998244353;

ll qpow(ll a,ll b){
    ll res = 1;
    ww(b){
        if(b&1)res = res*a%MOD;
        a = a*a%MOD;
        b>>=1;
    }
    return res;
}

struct Seg{
    struct node {
        ll l,r,mn,lazy;
        void update(ll val){
            mn += val;
            lazy += val;
        }
    }tree[maxn<<4];
    void pushdown(ll x){
        ll la = tree[x].lazy;
        if(la){
            tree[lson(x)].update(la);
            tree[rson(x)].update(la);
            tree[x].lazy = 0;
        }
    }
    void pushup(ll x){
        tree[x].mn = min(tree[lson(x)].mn,tree[rson(x)].mn);
    }
    void build(int x,int l,ll r){
        tree[x].l = l;tree[x].r = r;
        tree[x].mn = tree[x].lazy = 0;
        if(l == r){
            tree[x].mn = 0;
            return;
        }
        ll mid = (l+r)/2;
        build(lson(x),l,mid);
        build(rson(x),mid+1,r);
        pushup(x);
    }
    void update(int x,int l,int r,ll val){
        int L = tree[x].l;int R = tree[x].r;
        if(l<=L&&R<=r){
            tree[x].update(val);
            return ;
        }
        pushdown(x);
        int mid = (L+R)/2;
        if(mid>=l)update(lson(x),l,r,val);
        if(r>mid)update(rson(x),l,r,val);
        pushup(x);
    }
    ll query(int x,int l,int r){
        int L = tree[x].l;int R = tree[x].r;
        if(l<=L&&R<=r){
            return tree[x].mn;
        }
        pushdown(x);
        int mid = (L+R)/2;
        ll ans = INF;
        if(mid>=l)ans = min(ans,query(lson(x),l,r));
        if(r>mid)ans = min(ans,query(rson(x),l,r));
        return ans;
    }
};

struct Seg seg2,seg3;
int m,n;
ll a,b,c;
int main()
{
    wT(){
        scf("%d%d",&n,&m);
        seg2.build(1,1,n);
        seg3.build(1,1,n);
        rep(i,m){
            scf("%lld%lld%lld",&a,&b,&c);
            if(c == 2)seg2.update(1,a,b,1);
            else if(c == 3)seg3.update(1,a,b,1);
        }
        ll _a = seg2.query(1,1,n);
        ll _b = seg3.query(1,1,n);
        ll ans = (qpow(2,_a)*qpow(3,_b))%MOD;
        printf("%lld\n",ans);
    }
}
