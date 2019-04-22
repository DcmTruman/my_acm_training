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

const int maxn = 10020;
const int maxm = 250020;	
int head[maxn];
int dis[maxn];
int dis1[maxn];
bool inq[maxn];

int ct = 0;
int n,m,s;
struct edge{
	int to;
	int len;
	int next;
}E[2*maxm];

struct ee{
	int u;
	int v;
	int l;
};

vector<ee>EE;

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

void spfa(int st){
	clr(dis,0x3f3f3f3f);
	clr(inq,0);
	dis[st] = 0;
	queue<int>Q;
	Q.push(st);
	inq[st] = true;
	
	while(!Q.empty()){
		int t = Q.front();
		Q.pop();
		inq[t] = false;
		for(int i = head[t];i!=-1;i=E[i].next){
			if(dis[E[i].to]>dis[t]+E[i].len){
				dis[E[i].to]=dis[t]+E[i].len;
				if(!inq[E[i].to]){
					inq[E[i].to] = true;
					Q.push(E[i].to);
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	while(~scanf("%d%d",&n,&m)){
		int u,v,l,b;
		clr(head,-1);
		clr(dis,0x3f3f3f3f);
		clr(dis1,0x3f3f3f3f);
		clr(inq,0);
		EE.clear();
		ct = 0;
		for(int i = 0;i<m;i++){
			scanf("%d%d%d",&u,&v,&l);
			addedge(u,v,l);
			addedge(v,u,l);
			EE.push_back((ee){u,v,l});
		}
		spfa(n-1);
		for(int i = 0;i<n;i++)dis1[i] = dis[i];
		spfa(0);
		int ans = 0;
		for(int i = 0;i<m;i++){
			int u = EE[i].u;
			int v = EE[i].v;
			int l = EE[i].l;
			if(dis[u]+dis1[v]+l == dis[n-1]||dis1[u]+dis[v]+l==dis[n-1])ans += l;
		}
		ans *= 2;
		cout<<ans<<endl;
		//for(int i = 1;i<=n;i++)cout<<dis[i]<<endl;
	}
	return 0;
}

/*
10 15
0 1 580
1 4 90
1 4 90
4 9 250
4 2 510
2 7 600
7 3 200
3 3 380
3 0 150
0 3 100
7 8 500
7 9 620
9 6 510
6 5 145
5 9 160

4 7
0 1 1
0 2 2
0 3 10
0 3 3
1 3 2
2 3 1
1 1 1
*/


