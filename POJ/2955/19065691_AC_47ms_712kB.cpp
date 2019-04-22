#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

#define INF 0x3f3f3f3f;
const int maxn = 1020;

int dp[120][120];

int main()
{
	string s;
	while(cin >> s && s != "end")
	{
		memset(dp,0,sizeof(dp));
		int slen = s.length();
		if(slen == 1){
			cout << "0" << endl;
			continue;
		}
		for(int i = 1;i<slen;i++){
			if(s[i] == ')' && s[i-1] == '('){
				dp[i-1][i] = 2;
				//cout << i-1 << " " << i << endl;
			}	
			else if(s[i] == ']' && s[i-1] == '['){
				dp[i-1][i] = 2;
				//cout << i-1 << " " << i << endl;
			}	
		}
		for(int i = slen-1;i>=0;i--){
			for(int j = i+1;j<slen;j++){
				if(s[i] == '(' && s[j] == ')'){
					//cout <<] i << " " << j << endl;
					dp[i][j] = dp[i+1][j-1] + 2;
				}
				else if(s[i] == '[' && s[j] == ']'){
					//cout <<] i << " " << j << endl;
					dp[i][j] = dp[i+1][j-1] + 2;
				}
				for(int k = i;k<j;k++){
					dp[i][j] = max(dp[i][j] , dp[i][k] + dp[k+1][j]);
				}
			}
		}
		cout << dp[0][slen-1] << endl;
	}
}
