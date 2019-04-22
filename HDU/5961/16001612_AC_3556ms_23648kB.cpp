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
# define maxn 3000
# define maxm 9000000

using namespace std;

int n,m;
int tol;
int head[maxn];
int dg[maxn];
char s[maxn][maxn];
int ans;
bool inq[maxn<<1];
struct Edge{
	int to,next;
}edge[maxm];
void init()
{
	tol = 0;
	ans = 0;
	clrf(head);
	clr0(dg);
	clr0(inq);
}

void addedge(int u,int v)
{
	edge[tol].to = v;
	edge[tol].next = head[u];
	head[u] = tol++;
}


int main()
{
	fuckio
	wT(){
		init();
		//int ans = 0;
		sc(n);
		char c;
		rep(i,n){
			rep(j,n){
				cin>>s[i][j];
				if(s[i][j] != '-'){
					addedge(i,j);
					dg[j]++;
				}
				
			}
		}
		queue<int>q;
		for(int i = 0;i<n;i++){
			if(dg[i] == 0){
				ans ++;
				inq[i] == true;
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(int i = head[u];~i;i = edge[i].next){
				int v = edge[i].to;
				if(inq[v])continue;
				dg[v] --;
				if(dg[v] == 0){
					ans ++;
					inq[v] = true;
					q.push(v);
				}
			}
		}
		//cout<<"Debug"<<ans<<endl;
		if(ans<n){
			prf("N\n");
			continue;
		}
		init();
		rep(i,n){
			rep(j,n){
				if(s[i][j] == 'P'){
					addedge(i,j);
					dg[j]++;
				} 
				else if(s[i][j] == 'Q'){
					addedge(j,i);
					dg[i]++;
				}
			}
		}
		for(int i = 0;i<n;i++){
			if(dg[i] == 0){
				ans ++;
				inq[i] == true;
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(int i = head[u];~i;i = edge[i].next){
				int v = edge[i].to;
				if(inq[v])continue;
				dg[v] --;
				if(dg[v] == 0){
					ans ++;
					inq[v] = true;
					q.push(v);
				}
			}
		}
		if(ans<n){
			prf("N\n");
			//continue;
		}
		else prf("T\n");

	}
}

