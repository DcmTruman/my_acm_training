#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

const int maxn = 1000020;
int gcd(int a,int b){
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
int main()
{
	init();
	int T,TT;
	cin>>T;
	TT = T;
	while(T--)
	{
		int l,r;
		cin>>l>>r;
		cout<<"Case #"<<TT-T<<": "<<ans[r]-ans[l-1]<<endl;
	}
} 















