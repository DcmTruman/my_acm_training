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
int n,m,w;
int ct = 0;
int dis[maxn];
bool inq[maxn];
int head[maxn];
int num[maxn];
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

bool spfa(){
	queue<int>Q;
	int st = 1;
	dis[st] = 0;
	Q.push(st);
	inq[st] = true;
	num[st]++;
	while(!Q.empty()){
		
		int t = Q.front();
		Q.pop();
		inq[t] = false;
		for(int i = head[t];i!=-1;i = E[i].next){
			int d = E[i].to;
		//	if(inq[d])continue;
			if(dis[d]>dis[t]+E[i].len){
				//fuck
				dis[d] = dis[t]+E[i].len;
				if(!inq[d]){
					inq[d] = true;
					Q.push(d);
					num[d]++;
					if(num[d]>n)return true;
				}
				
			}
		}
	}
	return false;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		clr(head,-1);
		ct = 0;
		clr(dis,0x3f3f3f3f);
		clr(num,0);
		clr(inq,0);
		cin>>n>>m>>w;
		for(int i = 0;i<m;i++){
			int u,v,l;cin>>u>>v>>l;
			addedge(u,v,l);
			addedge(v,u,l);
		}
		for(int i = 0;i<w;i++){
			int u,v,l;cin>>u>>v>>l;
			addedge(u,v,-l);
		}
		if(spfa())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}


	//fuck
	
	
}