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
# define _sz(x) (x).size()
# define qisok(q) (!(q).empty())
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
# define sl(x) scanf("%I64d",&(x))
# define pc(x) printf("%d\n",(x));
# define pl(x) printf("%I64d\n",(x));
# define scf scanf
# define prf printf
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 100000
# define maxm 202000


using namespace std;

int N,M;
int a,b,c;
struct Edge
{
    int from;
    int to,next;
    int cap,flow;
}edge[maxm];

int tol;
int head[maxn];
int gap[maxn],dep[maxn],cur[maxn];
int Q[maxn];
int S[maxn];
bool vis[maxn];
void init()
{
    tol = 0;
    clrf(head);
}

void add_edge(int u,int v,int w,int rw = 0)
{
    edge[tol].from = u;
    edge[tol].to = v;edge[tol].cap = w;edge[tol].flow = 0;
    edge[tol].next = head[u];head[u] = tol++;
    edge[tol].from = v;
    edge[tol].to = u;edge[tol].cap = rw;edge[tol].flow = 0;
    edge[tol].next = head[v];head[v] = tol++;
}

void BFS(int start,int end)
{
    clrf(dep);
    clr0(gap);
    gap[0] = 1;
    int front = 0,rear = 0;
    dep[end] = 0;
    Q[rear++] = end;
    ww(front!=rear){
        int u = Q[front++];
        for(int i= head[u];i!=-1;i = edge[i].next){
            int v = edge[i].to;
            if(dep[v] != -1)continue;
            Q[rear++] = v;
            dep[v] = dep[u]+1;
            gap[dep[v]]++;
        }
    }
}

int sap(int start,int end,int N)
{
    BFS(start,end);
    memcpy(cur,head,sizeof(head));
    int top = 0;
    int u = start;
    int ans = 0;
    ww(dep[start]<N){
        if(u == end){
            int Min = INF;
            int inser;
            rep(i,top){
                if(Min>edge[S[i]].cap-edge[S[i]].flow){
                    Min = edge[S[i]].cap-edge[S[i]].flow;
                    inser = i;
                }
            }
            rep(i,top){
                edge[S[i]].flow += Min;
                edge[S[i]^1].flow -= Min;
            }
            ans += Min;
            top = inser;
            u = edge[S[top]^1].to;
            continue;
        }
        bool flag = false;
        int v;
        for(int i = cur[u];i!=-1;i = edge[i].next){
            v = edge[i].to;
            if(edge[i].cap-edge[i].flow&&dep[v]+1 == dep[u]){
                flag = true;
                cur[u] = i;
                break;
            }
        }
        if(flag){
            S[top++] = cur[u];
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u];i!=-1;i = edge[i].next){
            if(edge[i].cap - edge[i].flow&&dep[edge[i].to]<Min){
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        }
        gap[dep[u]] -- ;
        if(!gap[dep[u]])return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if(u!=start)u = edge[S[--top]^1].to;
    }
    return ans;
}
void dfs(int now)
{
    //cout<<now<<endl;
    vis[now] = true;
    for(int i = head[now];i!=-1;i = edge[i].next){
        int t = edge[i].to;
        //cout<<edge[i].from<<" "<<edge[i].to<<" "<<edge[i].flow<<" "<<edge[i].cap<<endl;
        if(edge[i].cap&&edge[i].flow<edge[i].cap&&!vis[t]){
           //cout<<edge[i].from<<" "<<edge[i].to<<" "<<edge[i].flow<<" "<<edge[i].cap<<endl;
           dfs(t); 
        }
    }
}
int main()
{
    ww(~scf("%d%d",&N,&M)&&(M+N)){
        init();
        clr0(vis);
        rep(i,M){
            scanf("%d%d%d",&a,&b,&c);
            add_edge(a,b,c,c);
            //add_edge(b,a,c);
        }
        int mxflow = sap(1,2,N);
        //cout<<mxflow<<endl;
        dfs(1);
        repf(i,1,N){
            if(vis[i]){
                //cout<<i<<endl;
                for(int j = head[i];~j;j = edge[j].next){
                    if(!vis[edge[j].to]){
                        printf("%d %d\n",i,edge[j].to);
                    }
                }
            }
        }
        printf("\n");
    }
}