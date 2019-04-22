//0~n中多少个数字是含有49的
//dp[i][j]长度小于等于i
//dp[i][0],不包含49的个数
//dp[i][1]，首位为9且不包含49的个数
//dp[i][2],包含49的数的个数
//dp[i][0] = dp[i-1][0]*10-dp[i-1][1]
//dp[i][1] = dp[i-1][0]
//dp[i][2] = dp[i-1][2]*10+dp[i-1][1]
//dp[0][0] = 1;
//注意需要一个flag来表示前面出现了49与否，如果出现了，答案还需要加上dp[i-1][0] 
 

#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

#define clr(x) memset(x,0,sizeof(x));
typedef unsigned long long ll;

ll dp[27][3];
int cnt,bit[27],len;
ll n;
void init()
{
	clr(dp);
	dp[0][0] = 1;
	for(int i = 1;i<=20;i++){
		dp[i][0] = dp[i-1][0]*10-dp[i-1][1];
		dp[i][1] = dp[i-1][0];
		dp[i][2] = dp[i-1][2]*10+dp[i-1][1]; 
	}
}

int fnd(ll x)
{
	cnt = 0;
	clr(bit);
	while(x){
		bit[++cnt] = x%10;
		x/=10;
	}
	bit[cnt+1] = 0;
	return cnt;
} 
 

int main()
{
	init();
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		len = fnd(n+1);
		bool flag = false;
		ll ans = 0;
		for(int i = len;i>=1;i--){
			ans += bit[i]*dp[i-1][2];
			if(flag)ans+=bit[i]*dp[i-1][0];
			else if(bit[i]>4)ans+=dp[i-1][1];
			if(bit[i+1] == 4&&bit[i] == 9)flag = true;
		}
		cout<<ans<<endl;
	}
}