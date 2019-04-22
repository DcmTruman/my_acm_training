//区间dp
//dp[i][j]表示区间i~j内的最大匹配长度
//dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]) 


#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define clr(x) memset(x,0,sizeof(x));

const int maxn = 150;

double dp[maxn][maxn];
char s[maxn];
int len;

int main()
{
	while(~scanf("%s", s + 1))
	{
		if(s[1] == 'e')break;
		len = strlen(s + 1);
		clr(dp);
		for(int l = 1;l<=len;l++){
			for(int i = 1;i+l-1<=len;i++){
				int j = i+l-1;
				if((s[i] == '('&&s[j] == ')')||(s[i] == '['&&s[j] == ']'))dp[i][j] = dp[i+1][j-1]+2;
				for(int k = i;k<j;k++){
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
				}
			}
		}
		cout<<dp[1][len]<<endl;
		
	}
}