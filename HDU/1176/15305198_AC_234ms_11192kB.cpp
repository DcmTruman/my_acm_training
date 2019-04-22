#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 100020;

int aa[maxn][12];
int dp[maxn][12]; 
int n;
int x,T,maxT;
int main()
{
	while(cin>>n&&n)
	{
		maxT = 0;
		memset(aa,0,sizeof(aa));
		memset(dp,0,sizeof(dp));
		
		for(int i = 0;i<n;i++)
		{
			cin>>x>>T;
			aa[T][x]++;
			maxT = max(maxT,T);
		}
		for(int i = maxT;i>=0;i--)
		{
			for(int j = 0;j<=10;j++)
			{
				//cout<<aa[i][j];
				if(j == 0)
				{
					dp[i][j] = max(dp[i+1][j+1],dp[i+1][j])+aa[i][j];
				}
				else if(j == 10)
				{
					dp[i][j] = max(dp[i+1][j-1],dp[i+1][j])+aa[i][j];
				}
				else
				{
					dp[i][j] = max(dp[i+1][j-1],dp[i+1][j+1]);
					dp[i][j] = max(dp[i][j],dp[i+1][j])+aa[i][j];
				}
			}
		} 
		cout<<dp[0][5]<<endl;
	}
}