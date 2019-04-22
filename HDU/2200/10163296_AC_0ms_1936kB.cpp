#include<iostream>
using namespace std;

long long fuc(long long j,long long  N)
{
	long long temp = 1;
	for(long long i=1;i<=j;i++)
	{
		temp=temp*(N+1-i)/i;
	}

	return temp;
}
int main()
{
	long long N;
	long long ans;
	while(cin>>N)
	{
		ans = 0;
		for(long long i =2;i<=N;i++)
		{
			ans +=fuc(i,N)*(i-1);
		}
		cout<<ans<<endl;
	}
}
