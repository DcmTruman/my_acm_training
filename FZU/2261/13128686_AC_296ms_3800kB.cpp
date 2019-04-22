#include<iostream>
#include<queue>
#include<string.h>
#include<stdio.h>

using namespace std;
#define INF 0x3f3f3f3f
typedef struct _edge {
	int u, v, cost;
	int next;
}edge;
edge Edge[100020];
int ne = 0;
int headlist[100020];
int vis[100020];
int dis[100020];
int ed_num = 0, st_num = 0;
int a[100020], b[100020];
void addedge(int u, int v, int c)
{
	Edge[ne].u = u;
	Edge[ne].v = v;
	Edge[ne].cost = c;
	Edge[ne].next = headlist[u];
	headlist[u] = ne;
	ne++;
}

int spfa(int start)
{
	queue<int>Q;
	memset(vis, 0, sizeof(vis));
	memset(dis, INF, sizeof(dis));
	Q.push(start);
	vis[start] = 1;
	dis[start] = 0;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		vis[u] = 0;
		for (int i = headlist[u]; i!= -1; i = Edge[i].next)
		{
			int v = Edge[i].v, w = Edge[i].cost;
			if (dis[v]>dis[u] + w)
			{
				dis[v] = dis[u] + w;
				if (!vis[v])
				{
					vis[v] = 1;

					Q.push(v);
				}
			}
		}
	}
	int ret = INF;
	for (int i = 0; i<ed_num; i++)
	{
		if (dis[b[i]]<ret)
		{
			ret = dis[b[i]];
		}
	}
	return ret;
}

int main()
{
	int N, M;
	while (~scanf("%d%d", &N,&M))
	{

		memset(b, 0, sizeof(b));
		memset(headlist, -1, sizeof(headlist));
		ne = 0;
		int u, v, w;
		for (int i = 0; i<M; i++)
		{
			scanf("%d%d%d", &u, &v,&w);
			addedge(u, v, w);
		}
		scanf("%d", &st_num);
		int a;
		for (int i = 0; i<st_num; i++)
		{
			
			scanf("%d", &a);
			addedge(0, a, 0);
		}
		scanf("%d", &ed_num);
		for (int i = 0; i<ed_num; i++)
		{
			
			scanf("%d", &b[i]);
		}
		int ans = spfa(0);
		printf("%d\n", ans);
	}

}