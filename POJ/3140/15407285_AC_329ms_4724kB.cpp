#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<vector>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck"<<endl;
#define LSon(x) 2*(x)
#define RSon(x) 2*(x)+1




using namespace std;
typedef long long ll;

ll _abs(ll x){
	return (x>0)?x:-x;
}

const int maxn = 100020;
struct{
	int to;
	int next;
}edge[2*maxn];


int cnt = 0,n,m;
ll f[maxn];
ll head[maxn];
ll mn;
ll aa[maxn];
bool visit[maxn];

void addedge(int u,int v){
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void dfs(int x){
	visit[x] = true;
	for(int i = head[x];i!=-1;i=edge[i].next){
		if(!visit[edge[i].to]){
			dfs(edge[i].to);
			f[x] += f[edge[i].to];
		}
	}
	f[x] += aa[x];
}


int main()
{
	int ks = 1;
	while(cin>>n>>m&&!(n==0&&m==0)){
		clr(head,-1);
		clr(visit,0);
		//clr(edge,-1);
		clr(f,0);
		
		cnt = 0;
		for(int i = 1;i<=n;i++)scanf("%lld",&aa[i]);
		for(int i = 1;i<=m;i++){
			int u,v;scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		dfs(1);
		mn = 1e18;
		for(int i = 1;i<=n;i++)mn = min(mn,_abs(f[1]-f[i]-f[i]));
		printf("Case %d: %lld\n",ks++,mn);
	}
	return 0;
} 


