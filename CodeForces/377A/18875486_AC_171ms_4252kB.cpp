#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <stack>

using namespace std;
int n,m;
int mp[520][520];
int vis[520][520];
int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
bool isok(int x,int y)
{
	if(x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}
struct node{
	int x;
	int y;
};

stack<node>ANS;
void bfs(int x,int y)
{
	node temp;
	node st;st.x = x;st.y = y;
	queue<node>Q;
	Q.push(st);
	vis[x][y] = true;
	while(!Q.empty())
	{
		node t = Q.front();
		ANS.push(t);
		Q.pop();
		for(int i = 0;i<4;i++)
		{
			int xx = t.x + mx[i];
			int yy = t.y + my[i];
			if(isok(xx,yy) && !vis[xx][yy] && mp[xx][yy])
			{
				vis[xx][yy] = true;
				temp.x = xx;
				temp.y = yy;
				Q.push(temp);
			}
		}
	}
}
int k;
int main()
{
	cin >> n >> m >> k;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			char c;cin >> c;
			if(c == '.')mp[i][j] = 1;
			else mp[i][j] = 0;
		}
	}
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(vis[i][j] || mp[i][j] == 0)continue;
			bfs(i,j);
		}
	}
	for(int i = 0;i<k;i++)
	{
		node t = ANS.top();
		ANS.pop();
		mp[t.x][t.y] = 2;
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(mp[i][j] == 0)cout << '#';
			else if(mp[i][j] == 1)cout << '.';
			else cout << 'X';
		}
		cout << endl;
	}
        return 0;
}