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
# define lowbit x&(-x)
# define ww(a) while(a)
# define sc(x) scanf("%d",&(x))
# define sl(x) scanf("%lld",&(x))
# define pc(x) printf("%d\n",(x));
# define pl(x) printf("%lld\n",(x));
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define scf scanf
# define prf printf
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll  long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 100
# define maxm 20000

using namespace std;

struct Edge{
	int to,next,cap,flow,cost;
}edge[maxm];
int head[maxn],tol;
int pre[maxn],dis[maxn];
bool vis[maxn];
int N;
void init(int n)
{
	N = n;
	tol = 0;
	clrf(head);
}
void addedge(int u,int v,int cap,int cost)
{
	edge[tol].to = v;
	edge[tol].cap = cap;
	edge[tol].cost = cost;
	edge[tol].flow = 0;
	edge[tol].next = head[u];
	head[u] = tol++;
	edge[tol].to = u;
	edge[tol].cap = 0;
	edge[tol].cost = -cost;
	edge[tol].flow = 0;
	edge[tol].next = head[v];
	head[v] = tol++;
}

bool spfa(int s,int t)
{
	queue<int>q;
	for(int i = 0;i<N;i++)
	{
		dis[i] = INF;
		vis[i] = false;
		pre[i] = -1;
	}
	dis[s] = 0;
	vis[s] = true;
	q.push(s);
	ww(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u];~i;i = edge[i].next){
			int v = edge[i].to;
			if(edge[i].cap>edge[i].flow&&dis[v]>dis[u]+edge[i].cost){
				dis[v] = dis[u]+edge[i].cost;
				pre[v] = i;
				if(!vis[v]){
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	if(pre[t] == -1)return false;
	else return true;
}

int mincostmaxflow(int s,int t,int &cost)
{
	int flow = 0;
	cost = 0;
	ww(spfa(s,t)){
		int MIN = INF;
		for(int i = pre[t];i!=-1;i=pre[edge[i^1].to]){
			if(MIN>edge[i].cap-edge[i].flow){
				MIN = edge[i].cap-edge[i].flow;
			}
		}
		for(int i = pre[t];i!=-1;i = pre[edge[i^1].to]){
			edge[i].flow += MIN;
			edge[i^1].flow -= MIN;
			cost += edge[i].cost*MIN;
		}
		flow  += MIN;
	}
	return flow;
}


int n,m,K;
int shneed[maxn][maxn];
int suhave[maxn][maxn];
int kcost[60][60][60];
int kneed[60];
int ksupply[60];
int main()
{
	ww(~scf("%d%d%d",&n,&m,&K)&&(n+m+K)){
		clr0(kneed);
		bool flag = true;
		repf(i,1,n){
			repf(j,1,K){
				sc(shneed[i][j]);//第i个商家需要第j钟商品的个数
				kneed[j] += shneed[i][j];
			}
		}		
		repf(i,1,m){
			repf(j,1,K){
				sc(suhave[i][j]);//第i个供应点有多少个第j种商品
			}
		}
		repf(i,1,K){
			repf(j,1,n){
				repf(k,1,m){
					sc(kcost[i][j][k]);//从第k个供应点传送到第j个商家第i种物品的每单位小号
				}
			}
		}
		int ans = 0;
		int cost;
		repf(k,1,K){
			init(m+n+2);
			repf(i,1,m){
				//每个供应点与源点建边
				addedge(0,i,suhave[i][k],0);
				repf(j,1,n){
					addedge(i,m+j,suhave[i][k],kcost[k][j][i]);
				}
			}
			repf(i,1,n){
				addedge(m+i,m+n+1,shneed[i][k],0);
			}
			ksupply[k] = mincostmaxflow(0,m+n+1,cost);
			if(ksupply[k]!=kneed[k])flag = false;
			ans += cost;
		}
		if(flag)pc(ans)else prf("-1\n");
		//else prf("-1\n");

	}	
}