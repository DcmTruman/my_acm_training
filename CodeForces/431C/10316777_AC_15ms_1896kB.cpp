#include<iostream>
#include<algorithm>
#define MOD 1000000007  
using namespace std;
int n, k, d;
long long dp[300][2];
int main()
{
	cin >> n >> k >> d;
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (i >= j)
			{
				if (j < d)
				{
					dp[i][0] += dp[i - j][0];
				}
				else
				{
					dp[i][1] += dp[i - j][0];
				}
				dp[i][1] += dp[i - j][1];
				dp[i][0] %= MOD;
				dp[i][1] %= MOD;
			}
		}
	}
	cout << dp[n][1] << endl;
}