#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck() cout<<"fuck:"<<__LINE__<<endl;
using namespace std;
typedef long long ll;

const int maxn = 100021;
vector<int>V[maxn];
int du[maxn];
int m,n;


int main()
{
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		clr(du,0);
		for(int i = 0;i<=n;i++)V[i].clear();
		for(int i = 0;i<m;i++){
			int a,b;cin>>a>>b;
			du[b]++;
			V[a].push_back(b);
		}
		queue<int>Q;
		for(int i = 1;i<=n;i++){
			if(du[i] == 0){
				Q.push(i);
			}
		}
		if(Q.empty()){
			cout<<"Wrong"<<endl;
			continue;
		}
		while(!Q.empty()){
			int t = Q.front();
			Q.pop();
			for(int i = 0;i<V[t].size();i++){
				du[V[t][i]]--;
				if(du[V[t][i]] == 0)Q.push(V[t][i]);
			}
		}
		bool flag = true;
		for(int i = 1;i<=n;i++){
			if(du[i]!=0){
				flag = false;
				break;
			}
		}
		if(flag)cout<<"Correct"<<endl;
		else cout<<"Wrong"<<endl;
	}
	
	return 0;
} 