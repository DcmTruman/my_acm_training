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
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 1000020


using namespace std;
map<ll,ll>m;
ll a[maxn];
ll f[maxn];

void geta(ll n,ll s,ll w){
    ll i;
    ll g=s;
    for(i=0;i<n;i++){
        a[i]=g;
        if(a[i]==0){
            a[i]=g=w;
        }
        if(g%2==0) g=g/2;
        else g=(g/2)^w;
    }
}

int main()
{
    ll n,w,s;
    wT(){
        scanf("%lld%lld%lld",&n,&s,&w);
        clr0(f);
        geta(n,s,w);
        m.clear();
        f[0] = a[0];
        repf(i,1,n-1){
            f[i] = f[i-1]^a[i];
        }
        m[0] = 1;
        ll ans = 0;
        rep(i,n){
            ll tmp = f[i];
            ans += m[tmp];
            m[tmp]++;
        }
        printf("%lld\n",n*(n+1)/2-ans);
    }
    return 0;
}