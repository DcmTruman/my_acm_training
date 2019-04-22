#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
#define clr(x,b) memset(x,(b),sizeof(x))

using namespace std;
const int maxn = 100020;
const int maxm = 100020;

vector<int>V[maxn];
queue<int>Q;
vector<int>ans;
int ru[maxn];
int m,n;




int main()
{
	while(cin>>n>>m&&!(m==0&&n==0)){
		for(int i = 0;i<=n;i++)V[i].clear();
		while(!Q.empty())Q.pop();
		clr(ru,0);
		ans.clear();
		for(int i = 0;i<m;i++){
			int a,b;cin>>a>>b;
			V[a].push_back(b);
			ru[b]++;
		}
		for(int i = 1;i<=n;i++){
			if(!ru[i])Q.push(i);
		}
		while(!Q.empty()){
			int t = Q.front();
			Q.pop();
			ans.push_back(t);
			for(int i = 0;i<V[t].size();i++){
				ru[V[t][i]]--;
				if(ru[V[t][i]] == 0)Q.push(V[t][i]);
			}
		}
		for(int i = 0;i<ans.size();i++){
			if(i)cout<<" "<<ans[i];
			else cout<<ans[i];
		}
		cout<<endl;
		
	}
}