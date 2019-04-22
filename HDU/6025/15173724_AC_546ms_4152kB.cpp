#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long ll;

const int maxn = 100020;

ll gcd(ll a,ll b)
{
	return (b!=0)?gcd(b,a%b):a;
}

ll a[maxn];
ll aa[maxn];
ll bb[maxn];

int main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i = 0;i<n;i++)
		{
			cin>>a[i];
		}
		
		
		aa[0] = 0;
		bb[n-1] = 0;
		for(int i = 1;i<n;i++)
		{
			aa[i] = gcd(aa[i-1],a[i-1]);
		}
		for(int i = n-2;i>=0;i--)
		{
			bb[i] = gcd(bb[i+1],a[i+1]);
		}
		
		
		ll ans = 0,pos = 0;
		for(int i = 0;i<n;i++)
		{
			
			ll temp = gcd(aa[i],bb[i]);
			//cout<<aa[i]<<" "<<bb[i]<<" "<<temp<<endl;
			if(temp>ans)
			{
				ans = temp;
				pos = i;
			}
		}
		cout<<ans<<endl;
	}

	
	
}