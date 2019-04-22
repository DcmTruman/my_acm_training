#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

struct node{
	int x,d;
};
const int maxn = 1e5+20;

vector<int>V[120];
vector<int>E[maxn];
int g[maxn];
int dis[maxn][120];

bool visit[maxn];


int n,m,k,s;


void bfs(int a)
{
	queue<node>Q;
	for(int i = 0;i<V[a].size();i++)
	{
		int t = V[a][i];
		node te;
		te.x = t;
		te.d = 0;
		Q.push(te);
	}
	while(!Q.empty())
	{
		node t = Q.front();
		Q.pop();
		dis[t.x][a] = min(t.d,dis[t.x][a]);
		for(int i = 0;i<E[t.x].size();i++)
		{
			int p = E[t.x][i];
			if(!visit[p])
			{
				node te;
				te.x = p;
				te.d = t.d+1;
				visit[p] = true;
				Q.push(te);
			}
		}
		
	}
}
int main()
{
	
	cin>>n>>m>>k>>s;
	int ans[maxn];
	memset(ans,0,sizeof(ans));
	for(int i = 1;i<=n;i++)
	{
		cin>>g[i];
		V[g[i]].push_back(i);
	}
	for(int i = 1;i<=m;i++)
	{
		int a,b;cin>>a>>b;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for(int i = 1;i<=k;i++)
	{
		memset(visit,0,sizeof(visit));
		bfs(i);
	}
	
	for(int i = 1;i<=n;i++)
	{
		sort(dis[i]+1,dis[i]+1+k);
		for(int j = 1;j<=s;j++)ans[i]+=dis[i][j];
	}
	
	for(int i = 1;i<=n;i++)cout<<ans[i]<<" ";
	
}