#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
#include<map>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck:"<<__LINE__<<endl;
using namespace std;

const int maxn = 100200;
const int maxm  = 100200;
int S,T,n,m;
int ct = 0;
int cs = 0;
int dis[maxn];
bool visit[maxn];
int head[maxn];
map<string,int>M;
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
	start.x = 0;
	start.dis = 0;
	dis[0] = 0;
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
	while(cin>>n&&n!=-1){
		ct = 0;
		cs = 0;
		M.clear();
		clr(head,-1);
		clr(visit,0);
		clr(dis,0x3f3f3f3f);
		string st,ed;cin>>st>>ed;
		M[st] = cs++;
		if(st != ed)M[ed] = cs++;
		for(int i = 0;i<n;i++){
			string us;
			string vs;
			int l;
			int u;
			int v;
			cin>>us>>vs>>l;
			if(M.count(us))u = M[us];
			else {
				u = cs;
				M[us] = cs++;
			}
			if(M.count(vs))v = M[vs];
			else{
				v = cs;
				M[vs] = cs++;
			}
			addedge(u,v,l);
			addedge(v,u,l);
		}
		dijk();
		if(st == ed)cout<<"0\n";
		else if(dis[1] == 0x3f3f3f3f)cout<<"-1\n";
		else cout<<dis[1]<<endl;
	}


	//fuck
	
}