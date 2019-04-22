#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxn = 100020;
ll gcd(ll a,ll b){
	//cout<<a<<" "<<b<<endl;
	return (b!=0)?gcd(b,a%b):a;
}
bool isp[maxn];
int pr[maxn];
int k = 0;
int ans[maxn];
void init()
{
	memset(isp,1,sizeof(isp));
	memset(ans,0,sizeof(ans));
	
	
	for(int i = 2;i<maxn;i++)
	{
		if(isp[i])
		{
			pr[k++] = i;
			int cnt = 2;
			while(cnt*i<maxn)
			{
				isp[cnt*i] = false;
				cnt++;
			}
		}
	}
	

}

int main()
{
	ios::sync_with_stdio(false);
	init();
	
	int T,TT;
	ll x;
	scanf("%d",&T);
	TT = T;
	while(T--)
	{
		ll ans = 0;
		bool flag = false;
		scanf("%lld",&x);
		if(x<0){
			x = -x;
			flag = true;
		}
		for(int i = 0;i<k&&pr[i]*pr[i]<=x;i++)
		{
			
			if(x%pr[i] == 0)
			{
			
				ll kk = 0;
				
				while(x%pr[i] == 0)
				{
					kk++;
					x /= pr[i];
				}
				if(ans == 0)ans = kk;
				else ans = gcd(ans,kk);
			}
		}
		if(x>1)ans = 1;
		if(flag)
		{
			while(ans%2 == 0)
			{
				ans/= 2;
			}
		}
		printf("Case %d: %lld\n",TT-T,ans);
		
	}
	return 0;
} 
