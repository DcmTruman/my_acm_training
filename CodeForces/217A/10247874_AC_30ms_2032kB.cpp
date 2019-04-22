#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int ans = 0,n;
int x[120], y[120];
bool visit[120];
void dfs(int a)
{
	visit[a] = true;
	for (int i = 0; i < n; i++) {
		if (!visit[i] && (x[i] == x[a] || y[i] == y[a])) {
			dfs(i);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (!visit[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans - 1 << endl;
}