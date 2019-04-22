#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=2e5+5;
const LL INF=9999999999;
LL a[maxn];


int main()
{
	int n;
	while(cin>>n)
	{
		LL aa;
		LL cnt=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		LL Min=INF;
		for(int i=0;i<n-1;i++)
		{
			aa=abs(a[i]-a[i+1]);
			if(aa<Min) Min=aa;
		}
		for(int i=0;i<n-1;i++)
		{
			aa=abs(a[i]-a[i+1]);
			if(aa==Min) cnt++;
		}
		cout<<Min<<" "<<cnt<<endl;
	}
	return 0;
}
