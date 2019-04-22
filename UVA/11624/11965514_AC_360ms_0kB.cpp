#include<iostream>
#include<queue>
#include<string.h>
#include<string>
#include<algorithm>

using namespace std;
int m,n;
int M[1020][1020];
bool visit[1020][1020];
int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
bool isOK(int a,int b)
{
	if(a<0||b<0||a>=n||b>=m)return false;
	return true;
}
char Mc[1020][1020];
typedef struct _node{
	int x,y,t;
	void set(int a,int b,int c)
	{
		x = a;
		y = b;
		t = c;
	}
}node;
queue<node>Q;

void Bfs1()
{
	node temp;
	while(!Q.empty())
	{
		node t = Q.front();
		Q.pop();
		for(int i = 0;i<4;i++)
		{
			int xx = t.x+mx[i];
			int yy = t.y+my[i];
			if(isOK(xx,yy)&&Mc[xx][yy]!='#'&&M[xx][yy]==-1)
			{
				M[xx][yy] = t.t+1;
				temp.set(xx,yy,t.t+1);
				Q.push(temp);	
			}
		}
	}
	
}
int Bfs2(node J)
{
	node temp;
	Q.push(J);
	visit[J.x][J.y] = true;
	while(!Q.empty())
	{
		node t = Q.front();
		Q.pop();
		if(t.x == 0||t.x == n-1||t.y == 0||t.y == m-1)
		{
			return t.t+1;
		}
		for(int i = 0;i<4;i++)
		{
			int xx = t.x+mx[i];
			int yy = t.y+my[i];
			if(isOK(xx,yy)&&Mc[xx][yy]!='#'&&(t.t+1<M[xx][yy]||M[xx][yy] == -1)&&!visit[xx][yy])
			{
				temp.set(xx,yy,t.t+1);
				Q.push(temp);
				visit[xx][yy] = true;
			}
		}
	}
	return -1;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		while(!Q.empty())Q.pop();
		
		node J,F;
		memset(M,-1,sizeof(M));
		memset(visit,0,sizeof(visit));
		cin>>n>>m;
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				cin>>Mc[i][j];
				if(Mc[i][j] == 'J')
				{
					J.set(i,j,0);
				}
				else if(Mc[i][j] == 'F')
				{
					M[i][j] = 0;
					F.set(i,j,0);
					Q.push(F);
					
				}
			}
		}
		Bfs1();
		int ans = Bfs2(J);
		if(ans!=-1)cout<<ans<<endl;
		else cout<<"IMPOSSIBLE"<<endl;
	}
}
 