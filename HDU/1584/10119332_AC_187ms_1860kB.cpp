#include <cstdio>
#include <cstring>
using namespace std;
int pos[15];
bool vis[15];
int ans;
void input()
{
	int tmp;
	for (int i = 1; i <= 10; i++)
	{
		scanf("%d", &tmp);
		pos[tmp] = i;
	}
}
int Abs(int x)
{
	if (x < 0)
		return -x;
	return x;
}
void dfs(int step, int dis)
{
	if (dis >= ans)
		return;
	if (step == 9)
	{
		ans = dis;
		return;
	}
	for (int i = 1; i <= 9; i++)
		if (!vis[i])
		{
			vis[i] = 1;
			for (int j = i + 1; j <= 10; j++)
				if (!vis[j])
				{
					dfs(step + 1, dis + Abs(pos[i] - pos[j]));
					break;
				}
			vis[i] = 0;
		}
}
void solve()
{
	ans = 0x3f3f3f3f;
	memset(vis, 0, sizeof(vis));
	dfs(0, 0);
	printf("%d\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		input();
		solve();
	}
	return 0;
}