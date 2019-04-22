#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>

using namespace std;

char Mc[120][120];
bool visit[120][120];

int mx[8] = { 1,0,-1,0,1,1,-1,-1 };
int my[8] = { 0,1,0,-1,1,-1,1,-1 };
int n, m;

typedef struct _node {
	int x, y;
	void set(int a, int b)
	{
		x = a;
		y = b;
	}
}node;
queue<node>Q;

bool isOK(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m)return false;
	return true;
}

int main()
{
	node temp;
	while (cin >> n >> m)
	{
		int ans = 0;
		if (m == 0 && n == 0)break;

		while (!Q.empty())Q.pop();
		memset(visit, 0, sizeof(visit));
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> Mc[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (Mc[i][j] == '@' & !visit[i][j])
				{
					ans++;
					visit[i][j] = true;
					temp.set(i, j);
					Q.push(temp);
					while (!Q.empty())
					{
						node t = Q.front();
						Q.pop();
						for (int k = 0; k < 8; k++)
						{
							int xx = t.x + mx[k];
							int yy = t.y + my[k];
							if (isOK(xx, yy) && !visit[xx][yy] && Mc[xx][yy] == '@')
							{
								visit[xx][yy] = true;
								temp.set(xx, yy);
								Q.push(temp);
							}
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
}