#include<iostream>
#include<string.h>
#include<string>
using namespace std;

const int maxn = 30;

char _map[maxn][maxn];
int n,m;
int stx,sty;
int ans;
bool visit[maxn][maxn];
bool v[maxn][maxn];


int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};

bool isOK(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||visit[x][y]||_map[x][y]=='#'||v[x][y])return false;
	return true;
}

void dfs(int x,int y)
{
	//cout<<x<<endl;
	if(!v[x][y])
	{
		v[x][y] = true;
		ans++;
	}
	for(int i = 0;i<4;i++)
	{
		int xx = x+mx[i];
		int yy = y+my[i];
		if(isOK(xx,yy))
		{
			visit[xx][yy] = true;
			dfs(xx,yy);
			visit[xx][yy] = false;
		}
	}
}

int main()
{
	while(cin>>m>>n&&!(n==0&&m==0))
	{
		memset(visit,0,sizeof(visit));
		memset(v,0,sizeof(v));
		
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				cin>>_map[i][j];
				if(_map[i][j] == '@')
				{
					stx = i;
					sty = j;
				}
			}
		}
		ans = 1;
		visit[stx][sty] = true;
		v[stx][sty] = true;
		dfs(stx,sty);
		cout<<ans<<endl;
	}
	
}





