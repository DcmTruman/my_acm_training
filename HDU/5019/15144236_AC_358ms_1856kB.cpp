#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1000020;
ll gcd(ll a,ll b){
	//cout<<a<<" "<<b<<endl;
	return (b!=0)?gcd(b,a%b):a;
}
bool isp[maxn];

int ans[maxn];
void init()
{
	memset(isp,1,sizeof(isp));
	memset(ans,0,sizeof(ans));
	
	
	for(int i = 2;i<maxn;i++)
	{
		if(isp[i])
		{
			int cnt = 2;
			while(cnt*i<maxn)
			{
				isp[cnt*i] = false;
				cnt++;
			}
		}
	}
	
	for(int i = 2;i<maxn;i++)
	{
		if(isp[i])
		{
			int sum = 0;
			int d = i;
			while(d!=0)
			{
				sum += d%10;
				d /= 10; 
			}
			if(isp[sum])
			{
				ans[i] = ans[i-1]+1;
				//cout<<i<<" "<<sum<<endl;
			}
			else
			{
				ans[i] = ans[i-1];
			}
		}
		else ans[i] = ans[i-1];
	}
	

}
vector<ll>V;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		ll x,y,k;
		cin>>x>>y>>k;
		
		V.push_back(1);
		ll g = gcd(x,y);
		if(g!=1)V.push_back(g);
		for(ll i = 2;i*i<=g;i++)
		{
			if(g%i == 0)
			{
				V.push_back(i);
				V.push_back((ll)g/i);
			}
		}
		sort(V.begin(),V.end());
		if(V.size()<k)printf("-1\n");
		else printf("%I64d\n",V[V.size()-k]);
	}
	return 0;
} 
