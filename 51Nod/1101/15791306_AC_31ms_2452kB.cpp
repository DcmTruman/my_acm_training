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
# define maxn 200020


using namespace std;
const int mod = 1e9+7;
int n;
int dp[100020];
int mon[13] = {1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
void init()
{
    dp[0] = 1;
    rep(j,13){
        repf(i,mon[j],n){
            dp[i] = (dp[i-mon[j]]+dp[i])%mod;
        }
    }
}
int main()
{
    sc(n);
    init();
//    for(int i = 1;i<10;i++)cout<<dp[i]<<" ";
    pc(dp[n]);
}