#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;
typedef struct _node {
	int x, y;
	void set(int a, int b)
	{
		x = a;
		y = b;
	}
}node;
int mx[4] = { 0,1,0,-1 };
int my[4] = { 1,0,-1,0 };
bool isOK(int x, int y)
{
	if (x < 0 || x >= 5 || y < 0 || y >= 5)return false;
	return true;
}
bool maze[5][5];
bool visit[5][5];

bool flag = false;
stack<node> S;
void Dfs(int a, int b)
{
	if (flag)return;
	node temp;
	if (a == 4 && b == 4)
	{
		flag = true;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int xx = a + mx[i];
		int yy = b + my[i];
		if (isOK(xx, yy) && !visit[xx][yy]&&!flag&&maze[xx][yy] == false)
		{
			visit[xx][yy] = true;
			Dfs(xx, yy);
			if (flag)
			{
				temp.set(xx, yy);
				S.push(temp);
				return;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> maze[i][j];
		}
	}
	node temp;

	visit[0][0] = true;
	Dfs(0, 0);
	temp.set(0, 0);
	S.push(temp);
	while (!S.empty())
	{
		node t = S.top();
		S.pop();
		cout << "(" << t.x << ", " << t.y << ")" << endl;
	}
}