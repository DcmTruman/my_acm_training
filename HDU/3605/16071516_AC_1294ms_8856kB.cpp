# include <iostream>
# include <string>
# include <string.h>
# include <algorithm>                                                                                                                                         # include <queue>
# include <vector>
# include <map>
# include <stack>
# include <functional>
# include <math.h>
# include <set>
# include <time.h>
# define debug(x) cout<<" [ Debug : "<<#x<<" = "<<x<<" ]\n"
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
# define scf scanf
# define prf printf
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define Sz(x) (int)(x).size()
# define pb push_back
# define maxn (int)200000
# define maxm (int)2220000
using namespace std;


int N,M;

struct Edge
{
    int to,next,cap,flow;
}edge[maxm];

int tol;
int head[maxn];
int gap[maxn],dep[maxn],cur[maxn];
int Q[maxn];
int S[maxn];
void init()
{
    tol = 0;
    clrf(head);
}

void add_edge(int u,int v,int w,int rw = 0)
{
    edge[tol].to = v;edge[tol].cap = w;edge[tol].flow = 0;
    edge[tol].next = head[u];head[u] = tol++;
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

int n,m;
int tmp;
int num[1<<10+10];
vector<int>vv;
int main()
{
    ww(~scf("%d %d",&n,&m)){
        init();
        clr0(num);
        vv.clear();
        repf(i,1,n){
            int tp = 0;
            repf(j,1,m){
                sc(tmp);
                if(tmp == 1)tp = tp|(1<<(j-1));
            }
            if(num[tp])num[tp]++;
            else{
                num[tp]++;
                vv.pb(tp);
            }
        }
        int sz = Sz(vv);
        rep(i,sz){
            int tp = vv[i];
            add_edge(0,i+1,num[tp]);
            rep(j,m){
                if(tp&(1<<j))add_edge(i+1,j+sz+1,num[tp]);
            }
        }
        repf(i,1,m){
            sc(tmp);
            add_edge(i+sz,sz+m+1,tmp);
        }
        int flow = sap(0,m+sz+1,m+sz+2);
        if(flow == n)prf("YES\n");
        else prf("NO\n");
    }
   // system("pause");
    return 0;
}