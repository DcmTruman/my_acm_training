#include<iostream>
#include<string.h>
using namespace std;

int a[120];
int n,m;
int main()
{
	memset(a,0,sizeof(a));
	cin>>n>>m;
	for(int i = 0;i<m;i++)
	{
		int t;cin>>t;
		a[t]++;
	}
	int ans = 0;
	
	for(int i = 1;i<=100;i++)
	{
		int sum = 0;
		for(int j = 1;j<=100;j++)
		{
			//cout<<a[j]<<endl;
			sum += a[j]/i;
		}
		if(sum>=n)ans = i;
		else break;
	} 
	cout<<ans<<endl;
}


