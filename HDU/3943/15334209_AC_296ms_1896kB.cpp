//dp[i][j][k]第i位时有j个4和k个7的个数
//dp[i][j][k] += dp[i-1][j][k]*8//01235689 
//dp[i][j][k] += dp[i-1][j-1][k] //4
//dp[i][j][k] += dp[i-1][j][k-1] //7
//dp[0][0][0] = 1

 
# include<iostream>
#include<string.h>

using namespace std;

#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;

ll dp[22][22][22];
ll p,q,x,y,n;
int T;
int cnt,bit[22];

ll fnd(ll n)//查找1~n中的nya数的个数
{
	cnt = 0;
	while(n) 
	{
		bit[++cnt] = n%10;
		n/=10;
	}
	ll m1 = x;
	ll m2 = y;
	ll ans = 0;
	for(int i = cnt;i>=1;i--)
	{
		for(int j = 0;j<bit[i];j++)
		{
			if(j == 4)
			{
				if(m1)ans += dp[i-1][m1-1][m2];
			}
			else if(j == 7)
			{
				if(m2)ans += dp[i-1][m1][m2-1];
			}
			else
			{
				ans += dp[i-1][m1][m2];
			};
		}
		if(bit[i] == 4)m1--;
		else if(bit[i] == 7)m2--;
		if(m1<0||m2<0)return ans;
	}
	if(m1 == 0&&m2 == 0)ans++;
	return ans;
} 
void init()
{
	clr(dp);
	dp[0][0][0] = 1;
	for(int i = 1;i<22;i++)
	{
		for(int j = 0;j<=20;j++)
		{
			for(int k = 0;k<=20;k++)
			{
				dp[i][j][k] += dp[i-1][j][k]*8;
				if(j)dp[i][j][k] += dp[i-1][j-1][k];
				if(k)dp[i][j][k] += dp[i-1][j][k-1];
			}
		}
	}
}




int main()
{
	
	init();
	cin>>T;
	for(int tt = 1;tt<=T;tt++)
	{
		printf ("Case #%d:\n", tt);
		cin>>p>>q>>x>>y;
		ll tep = fnd(p);
		
		int qn;cin>>qn;
		while(qn--)
		{
			cin>>n;
			ll l = p;
			ll r = q;
			while(r-l>1)
			{
				ll mid = (l+r)>>1;
				ll pos = fnd(mid);
				if(pos-tep>=n)r = mid;
				else l = mid;
				//cout<<"fuck"<<endl;
			}
			
			if(fnd(l)-tep>=n)cout<<l<<endl;
			else if(fnd(r)-tep>=n)cout<<r<<endl;
			else cout<<"Nya!"<<endl;
		}
		
	}		
}