#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
#include<map>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck:"<<__LINE__<<endl;
using namespace std;

const int maxn = 20020;
const int maxm = 20020;
int head[maxn];
int dis[maxn];
int ct = 0;
int n,m,s;
struct edge{
	int to;
	int len;
	int next;
}E[2*maxm];

struct node{
	int x;
	int dis;
	bool operator < (const node b)const{
		return dis<b.dis;
	}
};
void addedge(int u,int v,int w){
	E[ct].to = v;
	E[ct].len = w;
	E[ct].next = head[u];
	head[u] = ct++;
}

void dijk(){
	int st = 0;
	dis[st] = 0;
	node start;
	start.x = 0;
	start.dis = 0;
	priority_queue<node>Q;
	Q.push(start);
	while(!Q.empty()){
		//fuck
		node t = Q.top();
		Q.pop();
		if(dis[t.x]!=t.dis)continue;
		for(int i = head[t.x];i!=-1;i=E[i].next){
			int d = E[i].to;
			int l = E[i].len;
			if(dis[d]>dis[t.x]+l){
				dis[d] = dis[t.x]+l;
				//cout<<i<<","<<l<<endl;
				node temp;
				temp.x = d;
				temp.dis = dis[d];
				Q.push(temp);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	while(~scanf("%d%d%d",&n,&m,&s)){
		int u,v,l,b;
		clr(head,-1);
		clr(dis,0x3f3f3f3f);
		ct = 0;
		for(int i = 0;i<m;i++){
			scanf("%d%d%d",&u,&v,&l);
			addedge(u,v,l);
		}
		int a;cin>>a;
		for(int i = 0;i<a;i++){
			scanf("%d",&b);
			addedge(0,b,0);
		}
		dijk();
		//for(int i = 1;i<=n;i++)cout<<dis[i]<<endl;
		if(dis[s] == 0x3f3f3f3f)printf("-1\n");
		else printf("%d\n",dis[s]);
	}
	return 0;
}
