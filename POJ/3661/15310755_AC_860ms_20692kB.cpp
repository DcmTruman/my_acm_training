//dp[i][j]//i分钟，疲劳度为j时的最大距离



//dp[i][j] = dp[i-1][j-1]+d[i]
//dp[i][0] = max(dp[i-k][k])

#include<iostream>
#include<string.h>


#define clr(x) memset(x,0,sizeof(x))
using namespace std;

const int maxn = 10020;
const int maxm = 520;

int n,m;

int dis[maxn];
int dp[maxn][maxm];
int main()
{
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>dis[i];
	
	clr(dp);
	
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			dp[i][j] = dp[i-1][j-1]+dis[i];
		}
		dp[i][0] = dp[i-1][0];
		for(int k = 1;k+k<=i;k++)
		{
			dp[i][0] = max(dp[i][0],dp[i-k][k]);
		}
	}
	cout<<dp[n][0]<<endl;
}