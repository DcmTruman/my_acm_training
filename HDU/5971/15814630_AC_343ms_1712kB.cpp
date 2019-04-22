# include <iostream>
# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <math.h>
# include <queue>
# include <string>
# include <vector>
# include <set>
# include <map>
# define INF 0x3f3f3f3f
# define Inf 0x7f7f7f7f
# define clr0(x) memset(x,0,sizeof(x))
# define clr1(x) memset(x,INF,sizeof(x))
# define clrf(x) memset(x,-1,sizeof(x))
# define rep(i,a) for(int i = 0;i<(a);i++)
# define repf(i,a,b) for(int i = (a);i<=(b);i++)
# define repu(i,a,b) for(int i = (a);i<(b);i++)
# define repd(i,a,b) for(int i = (a);i>=(b);i--)
# define lowbit(x) ((x)&(-x))
# define ww(a) while(a)
# define sc(x) scanf("%d",&(x))
# define sl(x) scanf("%lld",&(x)
# define pc(x) printf("%d\n",(x));
# define pl(x) printf("%lld\n",(x));
# define scf scanf
# define prf printf
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 1020

using namespace std;


const int maxm = 10020;


vector<int>G[maxn];
int color[maxn];
bool sure[maxn];
bool visit[maxn];
int m,n,x,y;
bool flag = true;

void dfs(int now){
	if(!flag)return;
	int c = color[now];
	for(int i = 0;i<G[now].size();i++){
		int t = G[now][i];
		if(color[t] == -1){
			color[t] = (c+1)%2;
			visit[t] = true;
			dfs(t);
		}
		else if(color[t]!=c){
			if(!visit[t]){
				visit[t] = true;
				dfs(t);
			}
		}
		else if(color[t] == c){
			flag = false;
			break;
		}
	}
	if(!flag)return;
}


int main(){
	while(cin>>n>>m>>x>>y){
		for(int i = 0;i<=n;i++)G[i].clear();
		clrf(color);
		clr0(sure);
		clr0(visit);
		for(int i = 0;i<m;i++){
			int a,b;cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		for(int i = 0;i<x;i++){
			int a;cin>>a;
			color[a] = 0;
			sure[a] = true;
		}
		for(int i = 0;i<y;i++){
			int a;cin>>a;
			color[a] = 1;
			sure[a] = true;
		}
		flag = true;
		for(int i = 1;i<=n;i++){
			if(sure[i]&&!visit[i]){
				//fuck
				visit[i] = true;
				dfs(i);
			}
			if(!flag)break;
		}
		if(!flag){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i = 1;i<=n;i++){
			if(!visit[i]&&G[i].size()>0){
				color[i] = 0;
				visit[i] = true;
				dfs(i);
			}
		}
		if(!flag){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i = 1;i<=n;i++){
			if(color[i]==-1){
				flag = false;
				break;
			}
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}