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

const int maxn = 100020;

struct edge{
	int u;
	int v;
};
int fa[maxn];
vector<int>vi[maxn];
vector<edge>wolf;
int n;
int ans;
char b[20];
int a;
void init(){
	for(int i = 0;i<=n;i++)fa[i] = i;
	for(int i = 0;i<=n;i++)vi[i].clear();
	wolf.clear();
}

int find(int x){
	return (fa[x] == x)?x:fa[x] = find(fa[x]);
}

void join(int a,int b){
	int x = find(a);
	int y = find(b);
	if(x!=y)fa[x] = y;
}

void dfs(int now){
	for(int i = 0;i<vi[now].size();i++){ans++;dfs(vi[now][i]);}
}

int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		init();
		ans = 0;
		for(int i = 1;i<=n;i++){
			scanf("%d%s",&a,b);
			if(b[0] == 'v'){vi[a].push_back(i);join(i,a);}
			else wolf.push_back((edge){i,a});
		}
		for(int i = 0;i<wolf.size();i++){
			int u = wolf[i].u;
			int v = wolf[i].v;
			if(find(u)==find(v)){ans++;dfs(v);}
		}
		printf("0 %d\n",ans);
	}
}


