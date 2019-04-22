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



int main()
{
	ll p,q,r,s;
	while(cin>>p>>q>>r>>s)
	{
		double ans = 1.0;
		q = min(q,p-q);
		s = min(s,r-s);
		ll l = max(s,q);
		for(ll i = 1;i<=l;i++)
		{
			if(i<=q)ans = ans*(p-q+i)/i;
			if(i<=s)ans = ans/(r-s+i)*i;
		}
		printf("%.05lf\n", ans);
	}
	
	
}