//状态压缩dp
//用二进制表示对字符串的保留状态
//枚举各种状态
//dp[j]表示在这种状态下，消去整个字符串的最小步数 
//judge(i)判断是否是回文串，如果是，返回1，如果不是，返回该字符串大小 
//dp[i] = min(dp[i],dp[k]+dp[k^i]),k是状态i的子状态 ,k^i是k的补集 ，也是状态i的子状态

#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

#define clr(x) memset(x,0,sizeof(x));

string s;
int dp[1<<17];
int st;
int len;

int judge(int a){
	int tp[17];
	int cnt = 0;
	clr(tp);
	for(int i = 0;i<len;i++){
		if(a&(1<<i))tp[cnt++] = i;
	}
	cnt--;
	for(int i = 0;i<=cnt/2;i++){
		if(s[tp[i]]!=s[tp[cnt-i]])return cnt;
	}
	return 1;
}


int main()
{
	int T;
	cin>>T;
	while(T--){
		clr(dp);
		cin>>s;
		len = s.length();
		st = 1<<len;
		st--;//1111..1111
		for(int i = 1;i<=st;i++){
			dp[i] = judge(i);
			for(int k = i;k>0;k=(k-1)&i){
				dp[i] = min(dp[i],dp[k]+dp[k^i]);
			}
		}
		cout<<dp[st]<<endl;
	}
}