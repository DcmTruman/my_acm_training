#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <stdio.h>

#define ll long long
using namespace std;

#define INF 0x3f3f3f3f;
const ll maxn = 1020;

ll dp[maxn][maxn];
ll dis[maxn][maxn];
ll pos[maxn];

int main()
{
	ll n;
	while(~scanf("%lld" , &n))
	{
		for(ll i = 1;i<=n;i++){
			scanf("%lld" , &pos[i]);
		}
		for(int i = 0;i<=n;i++){
			for(int j = 0;j<=n;j++){
				dis[i][j] = 0;
			}
		}
		for(ll i = 1;i<=n;i++){
			for(ll j = i+1;j<=n;j++){
				dis[i][j] = dis[i][j-1] + pos[j] - pos[(i+j) / 2];
			}
		}

		ll m; cin >> m;
		while(m -- )
		{
			ll a,b;
			scanf("%lld%lld" , &a ,&b);
			if(a > b)swap(a,b);
			printf("%lld\n",dis[a][b]);
		}

	}
}
