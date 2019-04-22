#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

#define INF 0x3f3f3f3f;
const int maxn = 1020;
int arr[maxn];

int dp[maxn][maxn];
int sum[maxn];

int main()
{
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			cin >> arr[i];	
			sum[i] = sum[i-1] + arr[i];
		}

		for(int l = 2;l<=n;l++){
			for(int i = 1;i+l-1<=n;i++){
				int j = i + l - 1;
				dp[i][j] = INF;
				for(int k = i;k<j;k++)
				{
					dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
				}
			}
		}

		cout << dp[1][n] << endl;
	}
}
