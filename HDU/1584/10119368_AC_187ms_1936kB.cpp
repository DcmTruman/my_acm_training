#include<iostream>
#include<math.h>
using namespace std;
int ans = 0x3f3f3f3f;
int ADD[15] = { 0, };
bool Vis[15] = { false };
void Dfs(int step, int dis)
{
	if (dis >= ans) { return; }
	if (step == 9) {
		ans = dis;
		return;
	}
	for (int i = 1; i <= 9; i++)
	{

		if (!Vis[i]) {
			Vis[i] = true;
			for (int j = i + 1; j <= 10; j++) {
				if (!Vis[j])
				{
					Dfs(step + 1, dis + abs(ADD[i] - ADD[j]));
					break;
				}
			}
			Vis[i] = false;
		}
	}
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		ans = 0x3f3f3f3f;
		for (int j = 1; j <= 10; j++) {
			int a;
			cin >> a;
			ADD[a] = j;
		}
		Dfs(0, 0);
		cout << ans << endl;
	}
}
