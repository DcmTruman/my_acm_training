#include <iostream>
#include <stdio.h>

#define ll long long
#define LL long long
using namespace std;


int main()
{
	ll m , n;
	while(cin >> m >> n)
	{
		ll temp,t;
		ll ans = 1;
		if(m == 0 && n ==0)break;
		t = min(m,n);
		temp = m + n - t + 1;
		for(long long i = 1;i<=t;i++)
		{
			ans = ans * temp / i;
			temp ++;
		}
		cout << ans << endl;
		
	}
}
