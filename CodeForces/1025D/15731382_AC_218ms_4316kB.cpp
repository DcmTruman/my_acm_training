# include <bits/stdc++.h>
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
# define sd(x) scanf("%I64d",&(x))
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define gcd(a,b) __gcd((a),(b))
# define maxn 1020
using namespace std;

//dp[i][j][0]区间能否构成左子树, 以i为根往左延伸到j能否构成树
//dp[i][j][1]区间能否构成右子树, 以i为根往右延伸到j能否构成树
//dp[k][j][0] == 1&&dp[k][i][1] == 1,区间j~i可以以k为根建树
//if(gcd(a[i+1],a[k])>1)以k为根的树可以称为i+1的左子树，dp[i+1][j][0] = 1;
//if(gcd(a[j-1],a[k])>1)同理，dp[j-1][i][1] = 1;

bool gcdok[maxn][maxn];
bool dp[maxn][maxn][2];
bool ok[maxn][maxn];
int n,a[maxn];
int main()
{
    sc(n);
    repf(i,1,n)sc(a[i]);
    repf(i,1,n){
        repf(j,1,i-1){
            gcdok[i][j] = gcdok[j][i] = gcd(a[i],a[j])>1;
        }
    }
    repf(i,1,n)dp[i][i][0] = dp[i][i][1] = true;
    repf(i,1,n){
        repd(j,i,1){
            repf(k,j,i){
                if(dp[k][j][0]&&dp[k][i][1]){
                    ok[j][i] = true;
                    dp[i+1][j][0]|=gcdok[i+1][k];
                    dp[j-1][i][1]|=gcdok[j-1][k];
                }
            }
        }
    }
    if(ok[1][n])printf("Yes\n");
    else printf("No\n");
}
