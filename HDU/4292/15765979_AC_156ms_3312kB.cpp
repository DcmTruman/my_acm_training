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
# define sl(x) scanf("%I64d",&(x))
# define pc(x) printf("%d\n",(x));
# define pl(x) printf("%I64d\n",(x));
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 100020


using namespace std;


const int MAXN = 1510;
const int MAXM = 200010;

 
struct Edge
{
	int to, next;
	int cap;
};
 
Edge edge[MAXM];
 
int N, F, D;
int cnt, src, des;
//cnt表示一共有几条边
int head[MAXN];
//head[i]表示节点i的第一条边的编号
int level[MAXN];
 
void addedge(int from, int to, int cap)
{
	edge[cnt].to = to;
	edge[cnt].cap = cap;
	edge[cnt].next = head[from];
	head[from] = cnt++;
 
	edge[cnt].to = from; 
	edge[cnt].cap = 0;  
	edge[cnt].next = head[to];
	head[to] = cnt++;
}
 
int bfs()
{
	queue<int> q;
	while (!q.empty())
		q.pop();
	memset(level, -1, sizeof(level));
	level[src] = 0; //源点的深度为0
	q.push(src);
 
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (edge[i].cap > 0 && level[v] == -1) //该边未访问过且该边有流量
			{
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	return level[des] != -1; //返回是否还存在连通路
}
 
int dfs(int u, int f)
{
	if (u == des)
		return f;
	int tem;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if (edge[i].cap > 0 && level[v] == level[u] + 1)
		{
			tem = dfs(v, min(f, edge[i].cap));
			if (tem > 0)
			{
				edge[i].cap -= tem;
				edge[i ^ 1].cap += tem; //更新边与反向边的流量
				return tem;
			}
		}
	}
	level[u] = -1; //表示已经走过该点
	return 0;
}
 
int Dinic()
{
	int ans = 0, tem;
	while (bfs())//如果还存在连通路
	{
		while (tem = dfs(src, INF)) //一直试图寻找增广路
		{
            //fuck
			ans += tem;
		}
	}
	return ans;
}
 

int x;
char stmp[220];
int main()
{
    fuckio
    ww(~scanf("%d%d%d",&N,&F,&D)){
        clrf(head);
        cnt = 0;
        src = 0;des = D+F+N+N+1;
        repf(i,1,F){
            sc(x);addedge(0,i,x);
        }
        repf(i,1,D){
            sc(x);addedge(i+F+N+N,D+F+N+N+1,x);
        }
        repf(i,1,N){
           addedge(i+F,i+F+N,1);
           scanf("%s",stmp);
           rep(j,F){
               if(stmp[j] == 'Y'){
                   addedge(j+1,F+i,1);
               }
           } 
        }
        repf(i,1,N){
            scanf("%s",stmp);
            rep(j,D){
                if(stmp[j] == 'Y'){
                    addedge(i+F+N,F+N+N+j+1,1);
                }
            }
        }
        pc(Dinic());
    }
}