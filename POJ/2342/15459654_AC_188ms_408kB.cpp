#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
#include<string>
#define clr(x,b) memset(x,(b),sizeof(x))

using namespace std;
const int maxn = 6020;
const int maxm = 200020;
typedef long long ll;

int fa[maxn];
bool visit[maxn];
int dp[maxn][2];
int n,root;

void dfs(int now){
	visit[now] = true;
	for(int i = 1;i<=n;i++){
		if(!visit[i]&&fa[i] == now){
			dfs(i);
			dp[now][1] += dp[i][0];
			dp[now][0] += max(dp[i][0],dp[i][1]);
		}
	}
}
int main()
{
	while(cin>>n){
		root = 0;
		clr(visit,0);
		for(int i = 1;i<=n;i++){
			cin>>dp[i][1];
		}
		int a,b;
		while(cin>>a>>b&&!(a==0&&b==0)){
			fa[a] = b;
			root = b;
		}
		dfs(root);
		cout<<max(dp[root][0],dp[root][1])<<endl;
	}
}