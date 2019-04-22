#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool f[100020];
vector<int>F;
typedef struct _FFF
{
	int a;
	int w;
}FFF;
vector<vector<FFF>>V;
bool cmp(FFF a, FFF b) {
	if ((!f[a.a] )&& f[b.a])return true;
	else if ((f[a.a]) && (!f[b.a])) return false;
	else if ((f[a.a]) && f[b.a])return a.w < b.w;
	else if ((!(f[a.a]) && (!f[b.a])))return a.w < b.w;
}
int n, m, k,ans=-1;
int main()
{
	cin >> n >> m >> k;
	V.resize(n + 5);
	for (int i = 0; i < m; i++) {
		int u, v, x;
		cin >> u >> v >> x;
		FFF temp = { v,x };
		V[u].push_back(temp);
		temp = { u,x };
		V[v].push_back(temp);
	}
	for (int i = 0; i < k; i++)
	{
		int b;
		cin >> b;
		f[b] = true;
		F.push_back(b);
	}
	for (int i = 0; i < k; i++)
	{
		int b = F[i];
		if (V[b].size()) {
			sort(V[b].begin(), V[b].end(), cmp);
			if (!f[V[b][0].a]) {
				if (ans == -1)
				{
					ans = V[b][0].w;
				}
				else
				{
					ans = (V[b][0].w < ans) ? V[b][0].w : ans;
				}
			}
		}
	}
	cout << ans << endl;
}