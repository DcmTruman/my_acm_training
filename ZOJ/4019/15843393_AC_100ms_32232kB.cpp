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
# define maxn 2020
# define maxm 20020


using namespace std;

ll k1,k2,c;
ll n,m;
ll aa[maxn],bb[maxn];
ll ans;
ll sum1[maxn],sum2[maxn];
ll dp[maxn][maxn];
int main()
{
   wT(){
        aa[0] = 0;bb[0] = 0;ans = 0;
        sum1[0] = 0;sum2[0] = 0;
        scanf("%lld%lld%lld",&k1,&k2,&c);
        scanf("%lld%lld",&n,&m);
        for(ll i = 1;i<=n;i++)scf("%lld",&aa[i]);
        for(ll i = 1;i<=m;i++)scf("%lld",&bb[i]);
        sort(aa+1,aa+n+1);sort(bb+1,bb+m+1);
        for(ll i = 1;i<=n;i++)sum1[i] = aa[i] + sum1[i-1];
        for(ll i = 1;i<=m;i++)sum2[i] = bb[i] + sum2[i-1];
        for(ll i = 1;i<=n;i++)for(ll j = 1;j<=m;j++)dp[i][j] = 0;
        ans = 0;
        for(ll i = 1;i<=n;i++){
            if(c>sum1[i-1]){
                dp[i][0] = dp[i-1][0]+k1*(c-sum1[i]);
                ans = max(ans,dp[i][0]);
            }
            //else break;
        }
        for(ll i = 1;i<=m;i++){
            if(c>sum2[i-1]){
                dp[0][i] = dp[0][i-1]+k2*(c-sum2[i]);
                ans = max(ans,dp[0][i]);
            }
            //else break;
        }
        for(ll i = 1;i<=n;i++){
            for(ll j = 1;j<=m;j++){
                if(c>(sum1[i]+sum2[j])){
                    dp[i][j] = max(dp[i-1][j]+k1*(c-sum1[i]-sum2[j]),dp[i][j-1]+k2*(c-sum1[i]-sum2[j]));
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        prf("%lld\n",ans);
   } 
    return 0;
}