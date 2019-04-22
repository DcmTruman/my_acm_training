//dp[i][j] = INF//初始化
//dp[i][i] = 0 
//if(s[i]==s[j])dp[i][j] = dp[i+1][j-1];
//dp[i][j] = min(dp[i][j],dp[i+1][j]+add[i],dp[i+1][j]+del[i]);
//dp[i][j] = min(dp[i][j],dp[i][j-1]+add[j],dp[i][j-1]+del[j]);
//i从大到小，j从小到大 

#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<stdio.h>
#define clr(x) memset(x,0,sizeof(x))
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 2020;

int dp[maxn][maxn];
int add[maxn];
int del[maxn];

int n,m; 
string s;

int main(){
	
	while(cin>>n>>m){
		cin>>s;
		clr(dp);
		clr(add);
		clr(del);
		for(int i = 0;i<n;i++){
			char c;cin>>c;
			//cout<<"*"<<c-'a'<<"*"<<endl;
			cin>>add[c-'a']>>del[c-'a'];
		}
		for(int i = 0;i<m;i++)dp[i][i] = 0;
		for(int i = m-1;i>=0;i--){
			for(int j = i+1;j<m;j++){
				dp[i][j] = INF;
				if(s[i] == s[j])dp[i][j] = dp[i+1][j-1];
				dp[i][j] = min(dp[i][j],min(dp[i+1][j]+add[s[i]-'a'],dp[i+1][j]+del[s[i]-'a']));
				dp[i][j] = min(dp[i][j],min(dp[i][j-1]+add[s[j]-'a'],dp[i][j-1]+del[s[j]-'a']));
			}
		}
		cout<<dp[0][m-1]<<endl;
	}
}