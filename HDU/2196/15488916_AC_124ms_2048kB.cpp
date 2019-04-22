#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck() cout<<"fuck:"<<__LINE__<<endl;
using namespace std;
typedef long long ll;

const int maxn = 10020;

struct node{
	int to;
	int len;
};

vector<node>V[maxn];
int n;
int dis1[maxn]; //到孩子结点的最大路 
int dis2[maxn];//到孩子结点的次最大路
int dis3[maxn];//经过根的最大路 

void dfs1(int now){
	int mx1 = 0,mx2 = 0;
	for(int i = 0;i<V[now].size();i++){
		node t = V[now][i];
		dfs1(t.to);
		int cos = dis1[t.to]+t.len;
		if(cos>=mx1){
			mx2 = mx1;
			mx1 = cos;
		}
		else if(cos>mx2){
			mx2 = cos;
		}
	}
	dis1[now] = mx1;
	dis2[now] = mx2;
}

void dfs2(int now){
	for(int i = 0;i<V[now].size();i++){
		node t = V[now][i];
		dis3[t.to]=max(dis3[now],dis1[t.to]+t.len==dis1[now]?dis2[now]:dis1[now])+t.len;
        dfs2(t.to);
	}
}

int main()
{
	while(cin>>n){
		for(int i = 0;i<=n;i++)V[i].clear();
		for(int i = 2;i<=n;i++){
			int a,b;cin>>a>>b;
			V[a].push_back((node){i,b});
		}
		int root = 1;
		clr(dis1,0);
		clr(dis2,0);
		clr(dis3,0);
		dfs1(root);
		dfs2(root);
		for(int i = 1;i<=n;i++)cout<<max(dis1[i],dis3[i])<<endl;	
	}
	return 0;
} 






