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

const int maxn = 1020;
const int maxm = 10020;


vector<int>G[maxn];
int color[maxn];
bool sure[maxn];
bool visit[maxn];
int m,n,x,y;
bool flag = true;

void dfs(int now){
	if(!flag)return;
	int c = color[now];
	for(int i = 0;i<G[now].size();i++){
		int t = G[now][i];
		if(color[t] == -1){
			color[t] = (c+1)%2;
			visit[t] = true;
			dfs(t);
		}
		else if(color[t]!=c){
			if(!visit[t]){
				visit[t] = true;
				dfs(t);
			}
		}
		else if(color[t] == c){
			flag = false;
			break;
		}
	}
	if(!flag)return;
}


int main(){
	while(cin>>n>>m>>x>>y){
		for(int i = 0;i<=n;i++)G[i].clear();
		clr(color,-1);
		clr(sure,0);
		clr(visit,0);
		for(int i = 0;i<m;i++){
			int a,b;cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		for(int i = 0;i<x;i++){
			int a;cin>>a;
			color[a] = 0;
			sure[a] = true;
		}
		for(int i = 0;i<y;i++){
			int a;cin>>a;
			color[a] = 1;
			sure[a] = true;
		}
		flag = true;
		for(int i = 1;i<=n;i++){
			if(sure[i]&&!visit[i]){
				//fuck
				visit[i] = true;
				dfs(i);
			}
			if(!flag)break;
		}
		if(!flag){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i = 1;i<=n;i++){
			if(!visit[i]&&G[i].size()>0){
				color[i] = 0;
				visit[i] = true;
				dfs(i);
			}
		}
		if(!flag){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i = 1;i<=n;i++){
			//if(color[])
			if(color[i]==-1){
				flag = false;
				break;
			}
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
