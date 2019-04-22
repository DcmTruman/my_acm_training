#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>


using namespace std;
int m,n;
char c;
int mp[120][120];
bool vis[120][120];
int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
int ans = 0;
bool isok(int x,int y)
{
	if(x < 0 || y < 0||x >= n || y >= m)return false;
	return true;
}
void dfs(int nowi,int nowj)
{
	vis[nowi][nowj] = true;
	for(int i = 0;i<4;i++){
		int xx = nowi + mx[i];
		int yy = nowj + my[i];
		if(isok(xx,yy) && vis[xx][yy]==false && mp[xx][yy] == 1){
			dfs(xx,yy);
		}
	}
}
int main()
{
	memset(vis,0,sizeof(vis));
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		for(int j= 0;j<m;j++){
			cin >> c;
			if(c == '.')mp[i][j] = 0;
			else mp[i][j] = 1;
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(vis[i][j] == true || mp[i][j] == 0)continue;
			ans ++;
			dfs(i,j);
		}
	}
	cout << ans << endl;
}