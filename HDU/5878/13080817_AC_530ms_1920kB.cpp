#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int cnt = 0;
ll num[1000100];
ll Pow(ll a, ll b) {
	ll r = 1, base = a;
	while (b) {
		if (b & 1) r *= base;
		base *= base;
		b >>= 1;
	}
	return r;
}
ll N;
ll x;
int main()
{

	
	for (int i = 0; i <= 31; i++)
	{
		ll ii = Pow(2, i);
		for (int j = 0; j <= 19; j++)
		{
			ll jj = Pow(3, j);
			for (int k = 0; k <= 12; k++)
			{
				ll kk = Pow(5, k);
				for (int q = 0; q <= 11; q++)
				{
					ll qq = Pow(7, q);
					ll temp = ii *jj;
					if (temp>1e9)break;
					temp *= kk;
					if (temp>1e9)break;
					temp *= qq;
					if (temp>1e9)break;
					num[cnt++] = temp;
				}
			}
		}


	}
	sort(num, num + cnt);
	
	scanf("%d", &N);
	for (int i = 0; i<N; i++)
	{
		
		scanf("%I64d", &x);
		int pos = lower_bound(num, num + cnt,x) - num;
		printf("%I64d\n", num[pos]);
	}
}