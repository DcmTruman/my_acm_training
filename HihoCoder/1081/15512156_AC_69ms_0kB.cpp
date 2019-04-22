#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck:"<<__LINE__<<endl;
using namespace std;

const int maxn = 1020;
const int maxm  = 10020;
int S,T,n,m;
int ct = 0;
int dis[maxn];
bool visit[maxn];
int head[maxn];
struct edge{
	int to;
	int len;
	int next;
}E[maxm]; 
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
	priority_queue<node>Q;
	node start;
	start.x = S;
	start.dis = 0;
	dis[S] = 0;
	Q.push(start);
	while(!Q.empty()){
		
		node t = Q.top();
		Q.pop();
		//visit[t.x] = true;
		if(t.dis!=dis[t.x])continue;
		for(int i = head[t.x];i!=-1;i = E[i].next){
			int to = E[i].to;
			//if(visit[to])continue;
			if(dis[to]>dis[t.x]+E[i].len){
				dis[to] = dis[t.x]+E[i].len;
				node temp;
				temp.x = to;
				temp.dis = dis[to];
				Q.push(temp);
			}
		}
	}
	
}
int main(){
	ct = 0;
	clr(head,-1);
	clr(visit,0);
	clr(dis,0x3f3f3f3f);
	cin>>n>>m>>S>>T;
	for(int i = 0;i<m;i++){
		int u,v,l;cin>>u>>v>>l;
		addedge(u,v,l);
		addedge(v,u,l);
	}
	dijk();
	//fuck
	cout<<dis[T]<<endl;
}