#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<string.h>

using namespace std;
typedef struct _node {
	int x, y, t;
	void set(int a, int b, int c)
	{
		x = a;
		y = b;
		t = c;
	}
}node;
int add[12][12];
bool visit[12][12];
string bdd[12];
queue<node>Q;
int m, n;
int mx[4] = { 1,0,-1,0 };
int my[4] = { 0,1,0,-1 };
bool isOK(int a, int b)
{
	if (a >= n || b >= m || a < 0 || b < 0)return false;
	return true;
}
const int maxn = 1234567;
int main()
{
	int T,ans = maxn,time;
	int count = 0;
	string s;
	node t, tt, temp;
	cin >> T;
	int TT = T;
	while (T--)
	{
		ans = maxn;
		while (!Q.empty())Q.pop();
		count = 0;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				add[i][j] = maxn;
			}
		}
		for (int i = 0; i < 12; i++)bdd[i] = "";
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> bdd[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < bdd[i].length(); j++)
			{

				if (bdd[i][j] == '#')
				{
					count++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < bdd[i].length(); j++)
			{
				for (int p = 0; p < n; p++)
				{
					for (int q = 0; q < bdd[p].length(); q++)
					{
						if (bdd[i][j] == '#'&& bdd[p][q] == '#')
						{
							time = 0;
							int tc = 0;
							int xx, yy;
							memset(visit, 0, sizeof(visit));
							temp.set(i, j, 0);
							Q.push(temp);
							visit[i][j] = true;
							if (!visit[p][q])
							{
								temp.set(p, q, 0);
								Q.push(temp);
								visit[p][q] = true;
							}
							while (!Q.empty())
							{
								t = Q.front();
								Q.pop();
								tc++;
								for (int k = 0; k < 4; k++)
								{
									xx = mx[k] + t.x;
									yy = my[k] + t.y;
									if (isOK(xx, yy) && !visit[xx][yy] && bdd[xx][yy] == '#')
									{
										visit[xx][yy] = true;
										tt.set(xx, yy, t.t + 1);
										time = t.t + 1;
										Q.push(tt);
									}
								}
							}
							if (tc == count)
							{
								ans = min(ans, time);
							}
						}
					}
				}
				
			}
		}
		if (ans == maxn)cout <<"Case "<<TT-T <<": -1" << endl;
		else cout << "Case " << TT - T << ": " << ans << endl;
		
	}
}