#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn = 1020;
const int maxm = 20020l;

int head[maxn],ct;
int dfn[maxn] , low[maxn] , instack[maxn];
int id[maxn];
int ind[maxn] , outd[maxn];
int indx,ans;
int n,tot;
stack<int>S;
void init(int n)
{
	for(int i = 0;i<=n;i++)head[i] = -1,dfn[i] = 0,low[i] = 0,instack[i] = 0 , id[i] = 0,ind[i] = outd[i] = 0;
	ct = 0;
	indx = 0;
	while(!S.empty())S.pop();
	ans = 0;
	tot = 0;
}
struct _edge{
	int v,next;
}edge[maxm];

void addedge(int u,int v)
{
	edge[ct].v = v;
	edge[ct].next = head[u];
	head[u] = ct ++;
}

void dfs(int now)
{
	dfn[now] = low[now] = ++indx;
	S.push(now);
	instack[now] = true;
	for(int i = head[now];~i;i = edge[i].next)
	{
		int to = edge[i].v;
		if(!dfn[to]){
			dfs(to);
			low[now] = min(low[now] , low[to]);
		}else if(instack[to]){
			low[now] = min(low[now] , dfn[to]);
		}
	}
	if(dfn[now] == low[now]){
		id[now] = ++tot;
		while(S.top()!=now){
			int t = S.top();
			S.pop();
			instack[t] = false;
			id[t]= tot;
		}
		instack[now] = false;
		S.pop();
	}
}
int main()
{
	while(~scanf("%d",&n))
	{
		init(n);
		int tmp;
		for(int i = 1;i<=n;i++){
			while(~scanf("%d",&tmp) && tmp != 0){
				addedge(i , tmp);
			}	
		}
		for(int i = 1;i<=n;i++){
			if(!dfn[i]){
				dfs(i);
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = head[i];~j;j = edge[j].next){
				int to = edge[j].v;
				if(id[to] != id[i]){
					outd[id[i]] ++;
					ind[id[to]] ++;
				}
			}
		}
		int ans1,ans2;
		ans1 = ans2 = 0;
		for(int i = 1;i<=tot;i++){
			if(!ind[i])ans1++;
			if(!outd[i])ans2++;
		}
		if(tot == 1)printf("1\n0\n");
		else printf("%d\n%d\n",ans1,max(ans1,ans2));
	}
}

		
