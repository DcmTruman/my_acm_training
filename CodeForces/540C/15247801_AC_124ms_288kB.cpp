#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

const int maxn = 520;
int n,m;
bool flag = false;

char _map[maxn][maxn];

int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};

bool isOK(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m)return false;
	return true;
}
typedef struct _node{
	int x;
	int y;
}node;

queue<node>Q;


int main()
{

	cin>>n>>m;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			cin>>_map[i][j];	
		}
	}
	
	node start,end;
	cin>>start.x>>start.y;
	start.x-=1;
	start.y-=1;
	cin>>end.x>>end.y;
	end.x -= 1;
	end.y -= 1;
	
	Q.push(start);
	while(!Q.empty())
	{
		node t = Q.front();
		Q.pop();
		
		for(int i = 0;i<4;i++)
		{
			int xx = t.x+mx[i];
			int yy = t.y+my[i];
			
			if(isOK(xx,yy))
			{
				if(xx==end.x&&yy==end.y)
				{
					if(_map[xx][yy]=='.')_map[xx][yy]='X';
					else {
						flag = true;
						break;
					}
					node next;
					next.x = xx;
					next.y = yy;
					Q.push(next);
				}
				else if(_map[xx][yy]=='.')
				{
					_map[xx][yy] = 'X';
					node next;
					next.x = xx;
					next.y = yy;
					Q.push(next);
				}
			}
		}
		if(flag)break;
		
	}
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
	
	
	
} 



