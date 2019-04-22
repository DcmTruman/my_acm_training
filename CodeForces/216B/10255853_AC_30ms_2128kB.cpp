	#include<iostream>
	#include<algorithm>
	#include<vector>
	using namespace std;
	bool visit[100020];
	int n, m, ans = 0, d, flag, jl = 0,ol=0;
	vector<vector<int>>V;
	void dfs(int a)
	{
		d++;
		visit[a] = true;
		if (!V[a].size()) {
			d = 0; return;
		}
		if (V[a].size() & 1) { 
			flag = 1;
		};
		for (int i = 0; i < V[a].size(); i++)
		{
			if (!visit[V[a][i]])
			{
				dfs(V[a][i]);
			}
		}
	}
	int main()
	{
		cin >> n >> m;
		V.resize(n + 5);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			V[a].push_back(b);
			V[b].push_back(a);
		}
		for (int i = 1; i <= n; i++)
		{
			d = 0;
			flag = 0;
			if (!visit[i])
			{
				visit[i] = true;
				dfs(i);
				if ((d & 1) && !flag)
				{
					ans++;
				}
				//else if (flag && (d & 1))jl++;
				//else if (flag && (!(d & 1)))ol++;
			}
		}
		if ((n - ans) & 1)ans++;
		cout << ans << endl;
	}
