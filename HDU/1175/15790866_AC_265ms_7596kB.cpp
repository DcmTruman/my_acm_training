#include<iostream>
#include<string.h>

using namespace std;

int _map[1020][1020];
int visit[1020][1020];
int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};
int n,m,ax,ay,bx,by;
int flag = false;
bool isOK(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m)return false;
	return true;
}
void init()
{
	memset(visit,-1,sizeof(visit));
	flag = false;
}

void dfs(int x,int y,int cnt,int dir)
{
	if(flag)return;
	if(cnt>2)return;
	if(x == bx&&y == by){flag = true;return;}
	if(visit[x][y]!=-1&&visit[x][y]<=cnt)return;
	if(_map[x][y]!=0)return;
	visit[x][y] = cnt;
	for(int i = 0;i<4;i++)
	{
		int xx = x+mx[i];
		int yy = y+my[i];
		if(isOK(xx,yy))
		{
			if(dir!=i)
			{
				dfs(xx,yy,cnt+1,i);
			}
			else
			{
				dfs(xx,yy,cnt,dir);
			}
		}		
		if(flag)return;
	}
}
int main()
{
	while(cin>>n>>m&&(m||n))
	{
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				cin>>_map[i][j];	
			}
		}
		int t;
		cin>>t;
		while(t--)
		{
			init();
			cin>>ax>>ay>>bx>>by;
			ax -=1;
			ay -=1;
			bx -= 1;
			by -= 1;
			if(_map[ax][ay]==0||_map[bx][by] == 0||_map[ax][ay]!=_map[bx][by])
			{
				cout<<"NO"<<endl;
				continue;
			}	
			visit[ax][ay] = 0;
			for(int i = 0;i<4;i++)
			{
				int xx =ax+mx[i];
				int yy =ay+my[i];
				if(isOK(xx,yy))
				{
					dfs(xx,yy,0,i);
				}
			}
			if(flag)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
return 0;
}