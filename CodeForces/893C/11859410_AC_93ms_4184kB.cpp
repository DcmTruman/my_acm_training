#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N = 100005;
int f[N], a[N];
ll find(ll x)
{
	return (f[x] == x) ? x :f[x] = find(f[x]);
}

void join(ll x, ll y)
{
	ll fx = find(x);
	ll fy = find(y);
	if (fx != fy)
	{
		f[fx] = fy;
		a[fy] = (a[fx]<a[fy]) ? a[fx] : a[fy];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	ll sum = 0, n, m;
	cin >> n >> m;
	for (ll i = 0; i <= n; i++)
	{
		f[i] = i;
	}
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (ll i = 1; i <= m; i++)
	{
		ll x, y; cin >> x >> y;
		join(x, y);
	}
	for (ll i = 1; i <= n; i++)
	{
		if (f[i] == i)
		{
			sum += a[i];
		}
	}
	cout << sum << endl;
	//system("pause");
	return 0;
}