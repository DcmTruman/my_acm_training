#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
#include<string>
#define clr(x,b) memset(x,(b),sizeof(x))

using namespace std;
const int maxn =  100020;
const int maxm = 100020;
struct node{
	int to;
	int cost;
};
vector<node>V[maxn];
int n;
int ans = 0;
bool visit[maxn];

void dfs(int a){
	int t1 = V[a][0].to;
	int t2 = V[a][1].to;
	if(!visit[t1]){
		ans += V[a][0].cost; 
		visit[t1] = true;
		dfs(t1);
	}
	else if(!visit[t2]){
		ans += V[a][1].cost;
		visit[t2] = true;
		dfs(t2);
	}
	else if(t1 == 1){
		ans += V[a][0].cost; 
	}
	else if(t2 == 1){
		ans += V[a][1].cost;
	}
}


int main()
{
	cin>>n;
	int sum = 0;
	for(int i = 0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		sum += c;
		V[a].push_back((node){b,0});
		V[b].push_back((node){a,c});
	}
	visit[1] = true;
	
	dfs(1);
	//cout<<ans<<endl;
	cout<<min(ans,sum-ans)<<endl;
	return 0;
}