#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int N;
	long long h,k,p=0;
	long long ans = 0;
	cin>>N>>h>>k;
	while(N--)
	{
		long long  a;
		cin>>a;
		if(p+a>h){ans++;p = 0;}
		p += a;ans += p/k;p %=k;
	}
	if(p)ans++;
	cout<<ans<<endl;
}