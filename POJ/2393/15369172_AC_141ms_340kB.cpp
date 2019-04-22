//dp[i],第i天生产1单位酸奶的最小花费 
//dp[i] = min(dp[i],dp[i-1]+s) 

#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<stdio.h>
#define clr(x) memset(x,0,sizeof(x))
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int maxn = 10020;

int dp[maxn]; 
int y[maxn];
int n,s;
ll ans;
int main(){
	while(cin>>n>>s){
		clr(dp);clr(y);ans = 0;
		for(int i = 0;i<n;i++)cin>>dp[i]>>y[i];
		for(int i = 1;i<n;i++)dp[i] = min(dp[i],dp[i-1]+s);
		for(int i = 0;i<n;i++)ans += dp[i]*y[i];
		cout<<ans<<endl;
	}
}

