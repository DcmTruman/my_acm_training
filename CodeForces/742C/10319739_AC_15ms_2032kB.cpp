#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>>V;
typedef long long LL;
int b[120];
int v[120];
bool h[120];
LL ans[120], num = 0,tnum,tans=0;
using namespace std;
int n;
LL gcd(LL a, LL b)
{
	if (b>a)
		swap(a, b);
	LL c;
	while (b>0)
	{
		c = a%b;  a = b;    b = c;
	}
	return a;
}
void dfs(int a)
{
	num++;
	int flag = 0;
	if (!v[V[a][0]]) {
		v[V[a][0]] = num+1;
		dfs(V[a][0]);
		if (h[V[a][0]])h[a] = true;
	}
	else
	{
		if (V[a][0] == tnum) {
			h[a] = true;
			LL t = num - v[V[a][0]] + 1;
			if (t & 1)ans[tans++] = t;
			else ans[tans++] = t / 2;
		}
	}
}
int main()
{
	cin >> n;
	V.resize(n + 5);
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++)
	{
		V[i].push_back(b[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!v[i]) {
			num = 0;
			tnum = i;
			v[i] = true;
			dfs(i);
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (h[i])count++;
	}
	if (count < n)cout << "-1" << endl;
	else
	{
		LL aaa;
		aaa = ans[0];
		for (int i = 1; i < tans ; i++)
		{
			aaa = aaa*ans[i] / gcd(aaa, ans[i]);
		}
		cout << aaa << endl;
	}
	
}