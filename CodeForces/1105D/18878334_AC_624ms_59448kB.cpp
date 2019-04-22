#include <stdio.h>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <stack>

using namespace std;
int n,m;
int mp[1020][1020];
int vis[1020][1020];
int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
int speed[20];
bool isok(int x,int y)
{
	if(x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}
struct node{
	int x;
	int y;
	int type;
	int time;
	int step;
	bool operator < (const node b) const{
		if(time == b.time){
			if(type == b.type){
				return step < b.step;
			}
			return type > b.type;
		}
		return time > b.time;
	}
};


bool cmp(node a,node b)
{
	return a.type < b.type;
}

int cnt[20];
vector<node>st_vec;
void bfs()
{
	node temp;
	node st;
	priority_queue<node>Q;
	for(int i = 0;i<st_vec.size();i++){
		Q.push(st_vec[i]);
		vis[st_vec[i].x][st_vec[i].y] = true;
	}
	while(!Q.empty())
	{
		node t = Q.top();
		Q.pop();
		if(t.step <= 0)continue;
		cnt[t.type] ++;
		for(int i = 0;i<4;i++)
		{
			{
				int xx = t.x +  mx[i];
				int yy = t.y +  my[i];
					
				if(isok(xx,yy) && !vis[xx][yy] && mp[xx][yy])
				{
					
					vis[xx][yy] = true;
					temp.x = xx;
					temp.y = yy;
					temp.type = t.type;
					if(t.step == 1){
						temp.step = speed[temp.type];
						temp.time = t.time + 1;
					}else{
						temp.step = t.step - 1;
						temp.time = t.time;
					}
					Q.push(temp);
				}
			}
		}
	}
}
int k;
int main()
{
	cin >> n >> m >> k;
	for(int i = 1;i<=k;i++){
		cin >> speed[i];
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			char c;cin >> c;
			if(c == '.')mp[i][j] = 1;
			else if(c == '#')mp[i][j] = 0;
			else{
				st_vec.push_back((node){i,j,(int)c - '0',1,speed[c-'0']});
				mp[i][j] = 1;
			}
		}
	}
	
	bfs();
	for(int i = 1;i <= k;i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
