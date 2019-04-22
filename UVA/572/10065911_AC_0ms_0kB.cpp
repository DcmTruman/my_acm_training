#include<iostream>
#include<queue>
using namespace std;
int Map[101][101];
int dx[10]={-1,0,1,-1,1,-1,0,1},dy[10]={-1,-1,-1,0,0,1,1,1};
int m,n;
bool isOk(int a,int b)
{
	if(a>=m||b>=n||a<0||b<0||Map[a][b]!=1)return false;
	return true;
}
typedef struct _Pos{int x,y;}Pos;
int main()
{
	cin>>m>>n;
	int ans ;
	while(m!=0&&n!=0)
	{
		ans = 0;
		queue<Pos> Q;
		for(int i =0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				char s;
				cin>>s;
				if(s=='*')
				{
					Map[i][j] = 0;
				}
				else
				{
					Map[i][j] = 1;
				}
			}
		}
		for(int i = 0;i<m;i++)
		{
			for(int j =0;j<n;j++)
			{
				if(Map[i][j] == 1)
				{
					ans++;
					Pos temp = {i,j};
					Q.push(temp);
					while(!Q.empty())
					{
						int x = Q.front().x;
						int y = Q.front().y;
						Q.pop();
						for(int i =0;i<8;i++)
						{
							if(isOk(x+dx[i],y+dy[i]))
							{
								Pos temp = {x+dx[i],y+dy[i]};
								Q.push(temp);
								Map[temp.x][temp.y] = 0;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		cin>>m>>n;
	}
}