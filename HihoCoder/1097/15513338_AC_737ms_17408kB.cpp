#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck:"<<__LINE__<<endl;
#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 1020;
bool visit[maxn];
int dis[maxn];
int G[maxn][maxn];
int ans = 0;
int n;
void prim(){
	dis[1] = 0;
	for(int i = 0;i<n;i++){
		int mn = INF;
		int pos = 0;
		for(int j = 1;j<=n;j++){
			if(visit[j])continue;
			if(dis[j]<mn){
				mn = dis[j];
				pos = j;
			}
		}
		if(pos == 0)break;
		visit[pos] = true;
		ans += dis[pos];
		//dis[pos] = 0;
		for(int j = 1;j<=n;j++){ 
			dis[j] = min(dis[j],G[pos][j]);
		} 
	}
}
int main(){
	clr(dis,INF);
	cin>>n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			int a;cin>>a;
			G[i][j] = a;
		}
	}
	prim();
	//fuck
	cout<<ans<<endl;
}