#include<iostream>
#include<algorithm>
using namespace std;
const long long mod = 1e9+7;
const int Max = 3e5+5;
long long add[Max],bdd[Max];
int main()
{
	long long sum = 0;
	int n;
	bdd[0]=1;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>add[i];
		bdd[i]=2*bdd[i-1]%mod;
	}
	sort(add+1,add+1+n);
	for(int i=1;i<=n;i++)
	{
		sum =(sum+(bdd[i-1]-bdd[n-i])*add[i])%mod;
	}
	cout<<sum<<endl;
}