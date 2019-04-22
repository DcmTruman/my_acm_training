#include <iostream>

using namespace std;

const int maxn =1020;

int dp[maxn][maxn];

int main()
{
	string a,b;
	while(cin >> a >> b){
		int la = a.length();
		int lb = b.length();
		for(int i = 0;i<=la;i++)dp[i][0] = 0;
		for(int j = 0;j<=lb;j++)dp[0][j] = 0;
		for(int i = 1;i<=la;i++){
			for(int j = 1;j<=lb;j++){
				if(a[i-1] == b[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
				}else{
					dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
				}
			}
		}
		cout << dp[la][lb] << endl;

	}
return 0;
}
