#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck:"<<__LINE__<<____endl
#define MOD (ll)(1e9+7)

using namespace std;

const int maxn = 120;
const int maxm = 1020;
int _mp[maxn][maxn];
int n,m;
int main()
{
	cin>>n>>m;
	clr(_mp,0x3f3f3f3f);
	for(int i = 0;i<=n;i++)_mp[i][i] = 0;
	for(int i = 0;i<m;i++){
		int u,v,l;cin>>u>>v>>l;
		if(_mp[u][v]>l){
			_mp[u][v] = l;
			_mp[v][u] = l;
		}
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				_mp[i][j] = min(_mp[i][j],_mp[i][k]+_mp[k][j]);
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cout<<_mp[i][j]<<" ";
		}
		cout<<endl;
	}
}
