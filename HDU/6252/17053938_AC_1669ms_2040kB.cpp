#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const long long INF=1e18;
vector<int> node[2010];
vector<long long> wt[2010];
queue<int> q;
long long dis[2010];
int vis[2010];
bool inqueue[2010];
bool self;

bool SPFA(int s,int n){
	int u,v,cnt;
	for(int i=1;i<=n;i++){
		dis[i]=INF; inqueue[i]=false; vis[i]=0;
	}
	q.push(s); dis[1]=0;
	vis[s]+=1; inqueue[s]=true;
	while(q.size()>0){
		u=q.front();
		//printf("debug %d\n",u);
		cnt=node[u].size();
		for(int i=0;i<cnt;i++){
			v=node[u][i];
			if(dis[v]>dis[u]+wt[u][i]){
				dis[v]=dis[u]+wt[u][i];
				if(!inqueue[v]){
					vis[v]+=1;
					if(vis[v]>n) return false;
					inqueue[v]=true;
					q.push(v);
				}
			}
		}
		inqueue[u]=false;
		q.pop();
	}
	return true;
}

void addedge(int u,int v,long long w){
	if(u==v && w<0){
		self=true;
	}
	node[u].push_back(v);
	wt[u].push_back(w);
}

int main(){
	int T,n,m,k,a,b,c,d;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d %d %d",&n,&m,&k);
		self=false;
		for(int i=1;i<n;i++){
			addedge(i,i+1,-1);
		}
		for(int i=0;i<m;i++){
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if(a==b && c==d){
				addedge(a,c,-k);
				addedge(c,a,k);
			}else if(a==b){
				addedge(c,a,k-1);
				addedge(a,d,-k-1);
			}else if(c==d){
				addedge(a,c,-k-1);
				addedge(c,b,k-1);
			}else{
				addedge(c,b,k-1);
				addedge(a,d,-k-1);
			}
		}

		bool flag=SPFA(1,n);
		//printf("Flag=%d\n",flag);
		printf("Case #%d: ",t);

		if(!flag || self){
			printf("IMPOSSIBLE\n");
		}else{
			if(dis[n]==INF) printf("IMPOSSIBLE\n");
			else{
				printf("%lld",-dis[2]);
				for(int i=3;i<=n;i++){
					printf(" %lld",dis[i-1]-dis[i]);
				}
				printf("\n");
			}
		}
		for(int i=1;i<=n;i++){
			node[i].clear(); wt[i].clear();
		}
	}
	return 0;
}