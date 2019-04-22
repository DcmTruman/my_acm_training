#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <string>

#define ll long long
#define LL long long
using namespace std;

int mx[4] = {1, 0 ,-1,0};
int my[4] = {0,1,0,-1};
int n,m;

bool isok(int x,int y)
{
	if(x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

struct node{
	int x;
	int y;
};

bool vis[50][50];
queue<node>Q;
int mp[50][50];
node st;
int main()
{
	
	while(cin >> m >> n)
	{
		if(m == 0 && n == 0)break;
		memset(vis,0,sizeof(vis));
		while(!Q.empty())Q.pop();
		
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				char c;
				cin >> c;
				if(c == '.'){
					mp[i][j] = 1;
				}else if(c == '#'){
					mp[i][j] = 0;
				}else if(c == '@'){
					mp[i][j] = 1;
					st.x = i;
					st.y = j;
					vis[i][j] = 1;
				}
			}
		}
		Q.push(st);
		int ans = 0;
		while(!Q.empty())
		{
			ans ++;
			node t = Q.front();
			Q.pop();
			for(int i = 0;i<4;i++){
				int xx = t.x + mx[i];
				int yy = t.y + my[i];
				if(isok(xx,yy) && (!vis[xx][yy]) && mp[xx][yy])
				{
					Q.push((node){xx,yy});
					vis[xx][yy] = true;
				}
			}
		}
		cout << ans << endl;
	}
}
