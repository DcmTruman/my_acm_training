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

//最长公共子序列+路径

char a[120],b[120],s[250];
int cnt = 0;
int dp[120][120];
int main()
{
    fuckio
    ww(~scf("%s%s",a+1,b+1)){
        clr0(dp);
        int lena = strlen(a+1);
        int lenb = strlen(b+1);
        repf(i,1,lena){
            repf(j,1,lenb){
                if(a[i] == b[j])dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i = lena;
        int j = lenb;
        cnt = 0;
        ww(dp[i][j]){
            if(a[i] == b[j])s[cnt++] = a[i],i--,j--;
            else if(dp[i-1][j]>dp[i][j-1])s[cnt++] = a[i],i--;
            else s[cnt++] = b[j],j--;
        }
        ww(i>=1)s[cnt++] = a[i],i--;
        ww(j>=1)s[cnt++] = b[j],j--;
        repd(k,cnt-1,0)prf("%c",s[k]);
        prf("\n");
    }
    return 0;
}