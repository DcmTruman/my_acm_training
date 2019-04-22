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

inline ll _abs(ll x){
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

bool cat[maxn];
bool visit[maxn];
vector<int>leaf;
void addedge(int u,int v){
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void dfs(int x,ll num){
	//cout<<x<<" "<<num<<endl;
	visit[x] = true;
	int cct = 0;
	for(int i = head[x];i!=-1;i=edge[i].next){
		if(!visit[edge[i].to]){
			cct++;
			
			if(!cat[edge[i].to]){
				f[edge[i].to] = f[x];
				dfs(edge[i].to,0);
			}
			else {
				f[edge[i].to] = max(f[x],num+1);
				dfs(edge[i].to,num+1);
			}
			
		}
	}
	if(cct == 0)leaf.push_back(x);
}


int main()
{
	int ks = 1;
	while(cin>>n>>m){
		leaf.clear();
		clr(head,-1);
		clr(visit,0);
		clr(cat,0);
		clr(f,0);
		cnt = 0;
		
		for(int i = 1;i<=n;i++)cin>>cat[i];
		for(int i = 1;i<=n-1;i++){
			int u,v;scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		if(cat[1])dfs(1,1);
		else dfs(1,0);
		//dfs(1,0);
		int cnt = 0; 
		for(int i = 0;i<leaf.size();i++){
			if(f[leaf[i]]<=m)cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
} 


