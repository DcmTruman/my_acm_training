#include<iostream> 
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int abc()
{
	double a[10001][2];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=n;i++)
	{
		a[i][1]=a[i][1]/3600;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][2]>=0)
		{
			a[i][2]+=4.5/a[i][1];
		}
		else
			a[i][2]=1000000000;
	}
	double fast=a[1][2];
	for(int i=2;i<=n;i++)
	{
		if(a[i][2]<fast)
		{
			fast=a[i][2];
		}
	}
	return ceil(fast);
}
int main()
{
	
	for(int i=1;i<100000;i++)
	{
		cin>>n;
		if(n)
		{
			cout<<abc()<<endl;
		}
		else 
			break;
	}
	//system("pause");
}