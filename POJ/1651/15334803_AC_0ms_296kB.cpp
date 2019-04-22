//区间dp
//dp[i][j]表示区间i~j的最小贡献，不包括i,j 
//dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j])
//k是指在上述区间中最后抽到的数是a[k]，i+1<=k<=j-1 

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

#define clr(x) memset(x,0,sizeof(x))

const int maxn = 120;

int a[maxn],dp[maxn][maxn],n;

int main()
{
	while(cin>>n)
	{
		for(int i = 0;i<n;i++)cin>>a[i];
		clr(dp);
		for(int i = 0;i<n-2;i++)dp[i][i+2] = a[i]*a[i+1]*a[i+2];
		
		for(int len = 3;len<n;len++)
		{
			for(int i = 0;i+len<n;i++)
			{
				int j = i+len;
				for(int k = i+1;k<j;k++)
				{
					if(dp[i][j] == 0)dp[i][j]=dp[i][k]+dp[k][j]+a[i]*a[k]*a[j];
					else	dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
				}
			}
		}
		cout<<dp[0][n-1]<<endl;
	}
}