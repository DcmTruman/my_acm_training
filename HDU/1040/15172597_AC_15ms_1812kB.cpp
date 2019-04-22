#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long ll;
int main()
{


	int a[1020];

	
	int T;
	cin>>T;
	while(T--)
	{
		int n;cin>>n;
		for(int i = 0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		for(int i = 0;i<n;i++)
		{
			if(i)cout<<" "<<a[i];
			else cout<<a[i];
		}
		cout<<endl;
		
	}
	return 0;
	
	
}