#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#define clr(x,b) memset(x,(b),sizeof(x))

using namespace std;
const int maxn = 100020;
const int maxm = 100020;
int m,n;
int d;
bool flag;
bool visit[maxn];
vector<int>V[maxn];

void dfs(int a){
	d++;
	visit[a] = true;
	if(!V[a].size()){
		d = 0;
		return;
	}
	if(V[a].size()&1){
		flag = true;
	}
	for(int i = 0;i<V[a].size();i++){
		if(!visit[V[a][i]])dfs(V[a][i]);
	}
}

int main()
{
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;cin>>a>>b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		d = 0;
		flag = false;
		if(!visit[i]){
			visit[i] = true;
			dfs(i);
			if((d&1)&&!flag)ans++;
		}
	}
	if ((n - ans) & 1)ans++;
	cout<<ans<<endl;
}