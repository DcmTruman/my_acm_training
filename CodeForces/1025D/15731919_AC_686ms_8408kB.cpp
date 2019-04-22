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

//dp[l][r][0],区间l~r以a[l-1]为根时是否满足条件
//dp[l][r][1],区间l~r在以a[r+1]为根时是否满足条件
int dp[maxn][maxn][2];
int a[maxn];
int dfs(int l,int r,int x)
{
    if(l>r)return 1;
    if(dp[l][r][x]!=-1)return dp[l][r][x];
    int y = (x==0)?a[l-1]:a[r+1];
    repf(i,l,r){
        if(gcd(y,a[i])==1)continue;
        if(dfs(l,i-1,1)&&dfs(i+1,r,0))return dp[l][r][x] = 1;
    }
    return dp[l][r][x] = 0;
}

int main()
{
    int n;sc(n);
    clrf(dp);
    repf(i,1,n)sc(a[i]);
    repf(i,1,n){
        if(dfs(1,i-1,1)&&dfs(i+1,n,0)){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}