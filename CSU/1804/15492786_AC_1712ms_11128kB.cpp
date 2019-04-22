#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck() cout<<"fuck:"<<__LINE__<<endl;
#define MOD (ll)(1e9+7)

using namespace std;
typedef long long ll;
const int maxn = 100020;

ll dp[maxn];
ll a[maxn];
ll b[maxn];
ll du[maxn];
vector<int>V[maxn];//反向建边 
  
vector<int>T;//拓扑排序 
int n,m;


int main()
{
	while(cin>>n>>m){
		clr(du,0);
		clr(dp,0);
		T.clear();
		for(int i = 0;i<=n;i++){
			V[i].clear();
		}
		for(int i = 1;i<=n;i++){
			cin>>a[i]>>b[i];
		}
		for(int i = 0;i<m;i++){
			int a,b;cin>>a>>b;
			du[a]++;
			V[b].push_back(a);
		}
		queue<int>Q;
		for(int i = 1;i<=n;i++){
			if(du[i] == 0)Q.push(i);
		}
		while(!Q.empty()){
			int t = Q.front();
			Q.pop();
			T.push_back(t);
			for(int i = 0;i<V[t].size();i++){
				int d = V[t][i];
				du[d]--;
				if(du[d] == 0)Q.push(d);
			}
		}
		for(int i = 0;i<T.size();i++){
			int d = T[i];
			for(int j = 0;j<V[d].size();j++){
				int dd = V[d][j];
				dp[dd] = (dp[dd]+dp[d]+b[d])%MOD;
			}
		}
		ll sum = 0;
		for(int i = 1;i<=n;i++){
			sum = (sum+(dp[i]*a[i])%MOD)%MOD;
		}
		cout<<sum<<endl;
		
	}
} 





