#include<iostream>
#include<string.h>
#include<algorithm>
#define clr(x) memset(x,1,sizeof(x))

typedef long long ll;
using namespace std;

const int maxn = 1020;
int aa[maxn];
int n;
int dp[maxn];

int main()
{
	while(cin>>n&&n)
	{
		for(int i = 1;i<=n;i++)cin>>aa[i];
		
		for(int i = 1;i<=n;i++)dp[i] = aa[i];
	
		for(int i = 2;i<=n;i++)
		{
			for(int j = 1;j<i;j++)
			{
				if(aa[i]>aa[j])
				{
					//cout<<j<<" "<<dp[j]<<endl;
					dp[i] = max(dp[i],dp[j]+aa[i]);
				}
			}
		}
		
		int mx = -1;
		for(int i = 1;i<=n;i++)
		{
			//cout<<dp[i]<<endl;
			mx = max(mx,dp[i]);
		}
		cout<<mx<<endl;
	}
	

}