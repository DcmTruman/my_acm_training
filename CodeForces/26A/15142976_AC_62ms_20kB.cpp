#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;


int gcd(int a,int b){
	//cout<<a<<" "<<b<<endl;
	return (b!=0)?gcd(b,a%b):a;
}
bool isp[3010];

int ans[3010];
void init()
{
	memset(isp,1,sizeof(isp));
	memset(ans,0,sizeof(ans));
	
	
	for(int i = 2;i<3010;i++)
	{
		if(isp[i])
		{
			int cnt = 2;
			while(cnt*i<=3010)
			{
				isp[cnt*i] = false;
				cnt++;
			}
		}
	}
	
	for(int i = 2;i<=3010;i++)
	{
		int cnt = 0;
		for(int j = 2;j<=i;j++)
		{
			if(i%j == 0&&isp[j])
			{
				cnt++;
			}
			if(cnt>2)break;
		}
		if(cnt == 2){ans[i] = ans[i-1]+1;
		}//
		else ans[i] = ans[i-1]+0;
	}
}
int main()
{
	init();
	int n;
	cin>>n;
	cout<<ans[n]<<endl;
} 















