#include<iostream>
#include<queue>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

char Mc[220][220];
bool visit1[220][220];
bool visit2[220][220];
int time1[220][220];
int time2[220][220];
int n,m;
typedef struct _node{
	int x,y,t;
	void set(int a,int b,int c)
	{
		x = a;
		y = b;
		t = c;
	}
	bool friend operator== (_node A,_node B)
	{
		if(A.x == B.x&&A.y == B.y)return true;
		return false;
	}
}node;
queue<node>Q;
vector<node>V;
int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};

bool isOK(int a,int b)
{
	if(a<0||b<0||a>=n||b>=m)return false;
	return true;
}
const int maxn =1234567;
int main()
{	ios::sync_with_stdio(false);
	node temp;
	node end;
	node Y,M;
	int ans;
	while(cin>>n>>m)
	{
		V.clear();
		ans = maxn;
		while(!Q.empty())Q.pop();
		memset(visit1,0,sizeof(visit1));
		memset(visit2,0,sizeof(visit2));
		memset(time1,-1,sizeof(time1));
		memset(time2,-1,sizeof(time2));
		
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				cin>>Mc[i][j];
				if(Mc[i][j] == 'Y')Y.set(i,j,0);
				else if(Mc[i][j] == 'M')M.set(i,j,0);
				else if(Mc[i][j] == '@')
				{
					end.set(i,j,0);
					V.push_back(end);
						
				}
			}
		}
		
		Q.push(Y);
		while(!Q.empty())
		{
			node t = Q.front();
			Q.pop();
			if(time1[t.x][t.y] == -1)time1[t.x][t.y] = t.t;
			else
			{
				time1[t.x][t.y] = min(time1[t.x][t.y],t.t);
			}
			for(int k = 0;k<4;k++)
			{
				
				int xx = t.x+mx[k];
				int yy = t.y+my[k];
				if(isOK(xx,yy)&&Mc[xx][yy] != '#'&!visit1[xx][yy])
				{
					visit1[xx][yy] = true;
					temp.set(xx,yy,t.t+11);
					Q.push(temp);
				}
			}
		}
		Q.push(M);
		while(!Q.empty())
		{
			node t = Q.front();
			Q.pop();
			if(time2[t.x][t.y] == -1)time2[t.x][t.y] = t.t;
			else
			{
				time2[t.x][t.y] = min(time2[t.x][t.y],t.t);
			}
			for(int k = 0;k<4;k++)
			{
				
				int xx = t.x+mx[k];
				int yy = t.y+my[k];
				if(isOK(xx,yy)&&Mc[xx][yy] != '#'&!visit2[xx][yy])
				{
					visit2[xx][yy] = true;
					temp.set(xx,yy,t.t+11);
					Q.push(temp);
				}
			}
		}
		

		for(int i = 0;i<V.size();i++)
		{
			end = V[i];
			if(time1[end.x][end.y] == -1||time2[end.x][end.y] == -1)continue;
			ans = min(ans,time1[end.x][end.y]+time2[end.x][end.y]);
		}

		cout<<ans<<endl;
	}
	return 0;
}
