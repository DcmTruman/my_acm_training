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
# define _sz(x) (x).size()
# define qisok(q) (!(q).empty())
# define clr0(x) memset(x,0,sizeof(x))
# define clr1(x) memset(x,INF,sizeof(x))
# define clrf(x) memset(x,-1,sizeof(x))
# define rep(i,a) for(int i = 0;i<(a);i++)
# define repf(i,a,b) for(int i = (a);i<=(b);i++)
# define repu(i,a,b) for(int i = (a);i<(b);i++)
# define repd(i,a,b) for(int i = (a);i>=(b);i--)
# define lowbit(x) ((x)&(-x))
# define ww(a) while(a)
# define sc(x) scanf("%d",&(x))
# define sl(x) scanf("%I64d",&(x))
# define pc(x) printf("%d\n",(x));
# define pl(x) printf("%I64d\n",(x));
# define scf scanf
# define prf printf
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn (1<<21)


using namespace std;
const int mod = 1e9+7;
//dp[x]当前状态下的天数期望
//dp[x] = sum((p*dp[x|(1<<j)]))+1/sum(p)
//dp[(1<<n)-1] = 0
int n;
double dp[maxn];
double p[maxn];
int main()
{
    fuckio
    ww(~sc(n)){
        double psum;
        clr0(dp);
        rep(i,n)scf("%lf",&p[i]);
        int _sta = (1<<n)-1;
        repd(i,_sta-1,0){
            psum = 0;
            dp[i] ++;
            rep(j,n)if(!(i&(1<<j)))dp[i] += dp[i|(1<<j)]*p[j],psum += p[j];
            dp[i]/=psum;
        }
        prf("%.4lf\n",dp[0]);
    }
}