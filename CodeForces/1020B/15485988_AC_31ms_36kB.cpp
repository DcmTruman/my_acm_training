#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck"<<endl;
using namespace std;
typedef long long ll;


int tree[1020];
int visit[1020];
bool v[1020];
int ans[1020];
int n;

int dfs(int a){
	//cout<<a<<","<<ans[a]<<endl;
	//if(ans[a]!=-1)return ans[a];
	if(visit[a])return a;
	
	visit[a] = true;
	int t = dfs(tree[a]);
	visit[a] = false;
	return t;
}
int main()
{
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>tree[i];
	
	
	clr(ans,-1);
	for(int i = 1;i<=n;i++){
		//cout<<"****"<<i<<"****"<<endl;
		ans[i]=dfs(i);
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<" ";
} 
