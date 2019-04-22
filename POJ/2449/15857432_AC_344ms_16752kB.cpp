/* ***********************************************
Author        :ck
Created Time  :2016年01月11日 星期一 16时39分56秒
************************************************ */
 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
int n,m;
const int Inf= 0x3f3f3f3f;
int dis[N];
int tot,head[N];
struct Edge{
	int to,nxt,w;
}edge[M*2];
vector<Edge> re[N];
void init(){
	tot=0;
	memset(head,-1,sizeof head);
	for(int i=1;i<=n;i++) re[i].clear();
}
void addEdge(int u,int v,int w){
	edge[tot].to=v;
	edge[tot].w=w;
	edge[tot].nxt=head[u];
	head[u]=tot++;
}
 
 
Edge t;
queue<int> q;
bool vis[N];
void spfa(int s){
	for(int i=1;i<=n;i++) dis[i]=Inf;
	dis[s]=0;
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) vis[i]=0;
	vis[s]=1;
	q.push(s);
	dis[s]=0;
 
	while(!q.empty()){
		int u=q.front();
		vis[u]=0;
		q.pop();
		for(int k=0;k<re[u].size();k++){
			t=re[u][k];
			int v=t.to;
			int w=t.w;
			if(dis[u]+w<dis[v]) {
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
			
		}
 
	}
 
}
 
struct A{
	int f,g,v;
	bool operator < (const A & a) const{
		if(f==a.f && g<a.g || f<a.f) return 0;
		return 1;
	}
};
A a;
int k,ss,tt;
priority_queue<A> que;
int Astar(){
	if(dis[ss]==Inf) return -1;
	if(ss==tt) k++;
	while(que.size()) que.pop();
	int cnt=0;
	a.v=ss;a.g=0;a.f=a.g+dis[a.v];
	que.push(a);
	while(!que.empty()){
		a = que.top();
		que.pop();
		int u=a.v;
		int ga=a.g;
		if(u==tt){
			cnt++;
			if(cnt==k) return a.f;
		}
		for(int k=head[u];~k;k=edge[k].nxt){
			int v=edge[k].to;
			int w=edge[k].w;
			a.v = v;
			a.g=ga+w;
			a.f=a.g+dis[a.v];
			que.push(a);
		}
	}
	return -1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int T;
	while(scanf("%d%d",&n,&m)==2){
		init();
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);		
			addEdge(u,v,w);
			t.to=u;
			t.w=w;
			re[v].push_back(t);
		}
		scanf("%d%d%d",&ss,&tt,&k);
	///	printf("S :%d T: %d k :  %d\n",ss,tt,k);
		spfa(tt);
	//	for(int i=1;i<=n;i++){
	//		printf("dis [%d]:%d\n",i,dis[i]);
	//	}
 
		printf("%d\n",Astar());
 
	}
    
}