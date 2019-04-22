#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <queue>
#define ll long long
using namespace std;

#define INF 0x3f3f3f3f;

const ll maxn = 2e5+20;
int head[maxn];
bool vis[maxn];
int cnt = 0;
int u,v,n,m,last;
struct Edge{
	int to,next;
}edge[maxn];

void init()
{
	for(int i = 0;i<maxn;i++)head[i] = -1 , vis[i] = 0;
	cnt = 0;
}

void addedge(int u,int v)
{
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

struct node{
	int x,step;
};
int bfs(int now)
{
	node st = (node){now , 0};
	for(int i = 0;i<=n;i++)vis[i] = 0;
	queue<node>Q;
	Q.push(st);
	int pos = -1;
	int mx = -1;
	while(!Q.empty())
	{
		node t = Q.front();
		Q.pop();
		if(mx < t.step){
			mx = t.step;
			pos = t.x;
		}
		int from = t.x;
		for(int i = head[from];~i;i = edge[i].next){
			int to = edge[i].to;
			if(!vis[to]){
				vis[to] = true;
				Q.push((node){to,t.step+1});
			}
		}
	}
	u = pos;
	return mx;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i = 0;i<n-1;i++){
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		bfs(1);
		int dis = bfs(u);
		while(m--){
			int tmp;scanf("%d",&tmp);
			int ans = (tmp-1 > dis)?(dis + (tmp-1 - dis)*2):(tmp-1)  ;
			printf("%d\n",ans);
		}			

	}
}
