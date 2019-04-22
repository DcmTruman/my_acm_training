

#include<iostream>
#include<string.h>
#include<algorithm>

#define clr(x) memset(x,0,sizeof(x))
using namespace std;

const int maxn = 120;




int n,m,k;
int dp[maxn][maxn];
int _map[maxn][maxn];

bool isOK(int x,int y)
{
	if(x<0||x>=n||y<0||y>=n)return false;
	return true;
}


int dx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};

int dfs(int x,int y)
{
	//cout<<x<<","<<y<<endl;
	if(dp[x][y])return dp[x][y];
	int mx =0;
	for(int i = 1;i<=k;i++)
	{
		for(int j = 0;j<4;j++)
		{
			int xx = x+i*dx[j];
			//int xx = 0;
			int yy = y+i*my[j];
			//cout<<xx<<","<<yy<<endl;
			if(isOK(xx,yy))
			{
				if(_map[xx][yy]>_map[x][y])
				{
					
					int temp = dfs(xx,yy);
					mx = max(mx,temp);
				}
			}
		}
	}	
	//cout<<mx<<endl;
	dp[x][y] = _map[x][y] + mx;
	return dp[x][y];
}
int main()
{
	while(cin>>n>>k&&n!=-1&&k!=-1)
	{
		clr(dp);
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<n;j++)
			{
				cin>>_map[i][j];
			}
		}
		
		dfs(0,0);
		cout<<dp[0][0]<<endl;
	}
	
}