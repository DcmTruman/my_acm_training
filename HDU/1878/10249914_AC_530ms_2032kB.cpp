#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int ans = 0,n,m,d=0,flag=1;
vector<vector<int>>V;
bool visit[1020];
void dfs(int a)
{
	if (!flag)return;
	if (ans)return;
	if (V[a].size() & 1)
	{
		flag = 0;
		return;
	}
	int f = 1;
	for (int i = 0; i < V[a].size(); i++)
	{
		if (!visit[V[a][i]])
		{
			f = 0;
			visit[V[a][i]] = true;
			dfs(V[a][i]);
		}
	}
	if (f)ans = 1;
	return;
}
int main()
{
	cin >> n;
	while (n != 0)
	{
		V.resize(n + 5);
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			V[a].push_back(b);
			V[b].push_back(a);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i] && i == 1)
			{
				visit[i] = true;
				dfs(i);
			}
			else if (!visit[i] && i != 1)
			{
				ans = 0;
				break;
			}
		}
		if (!flag)ans = 0;
		cout << ans << endl;
		ans = 0;
		V.clear();
		for (int i = 1; i <= n; i++)visit[i] = false;
		flag = 1;
		cin >> n;
	}
}