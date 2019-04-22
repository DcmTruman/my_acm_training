#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck:"<<__LINE__<<endl;
using namespace std;

const int maxn = 1e5+21;
const int maxm  = 1e6+20;
int S,T,n,m;
int ct = 0;
int dis[maxn];
bool inq[maxn];
int num[maxn];
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

void spfa(){
	queue<int>Q;
	Q.push(S);
	inq[S] = true;
	dis[S] = 0;
	num[S]++;
	while(!Q.empty()){
		int t = Q.front();
		Q.pop();
		inq[t] = false;
		for(int i = head[t];i!=-1;i = E[i].next){
			int x = E[i].to;
			int l = E[i].len;
			if(dis[x]>dis[t]+l){
				dis[x] = dis[t]+l;
				if(!inq[x]){
					inq[x] = true;
					Q.push(x);
					num[x] ++ ;
					if(num[x]>n)return;
				}
			}
		}
	}
}


int main(){
	ct = 0;
	clr(head,-1);
	clr(inq,0);
	clr(dis,0x3f3f3f3f);
	clr(num,0);
	cin>>n>>m>>S>>T;
	for(int i = 0;i<m;i++){
		int u,v,l;cin>>u>>v>>l;
		addedge(u,v,l);
		addedge(v,u,l);
	}
	spfa();
	//fuck
	cout<<dis[T]<<endl;

}