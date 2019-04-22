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

int N,M;

struct Edge
{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};

struct Dinic
{
    int n,m,s,t;
    vector<Edge>edges;
    vector<int>G[maxn];
    bool vis[maxn]; //BFS鐨勪娇鐢?
    int d[maxn]; //浠庤捣鐐瑰埌i鐨勮窛绂?
    int cur[maxn]; //褰撳墠寮т笅鏍?

    void init(){
        clr0(vis);
        clr0(d);
        clr0(cur);
        edges.clear();
        rep(i,maxn)G[i].clear();
    }
    void addedge(int from,int to,int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        int  m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool bfs()
    {
        memset(vis,0,sizeof(vis));
        queue<int>Q;
        Q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!Q.empty())
        {
            int x=Q.front();Q.pop();
            for(int i=0;i<G[x].size();i++)
            {
                Edge&e=edges[G[x][i]];
                if(!vis[e.to]&&e.cap>e.flow)//鍙€冭檻娈嬮噺缃戠粶涓殑寮?
                {
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }

        }
        return vis[t];
    }

    int dfs(int x,int a)//x琛ㄧず褰撳墠缁撶偣锛宎琛ㄧず鐩墠涓烘鐨勬渶灏忔畫閲?
    {
        if(x==t||a==0)return a;//a绛変簬0鏃跺強鏃堕€€鍑猴紝姝ゆ椂鐩稿綋浜庢柇璺簡
        int flow=0,f;
        for(int&i=cur[x];i<G[x].size();i++)//浠庝笂娆¤€冭檻鐨勫姬寮€濮嬶紝娉ㄦ剰瑕佷娇鐢ㄥ紩鐢紝鍚屾椂淇敼cur[x]
        {
            Edge&e=edges[G[x][i]];//e鏄竴鏉¤竟
            if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(!a)break;//a绛変簬0鍙婃椂閫€鍑猴紝褰揳!=0,璇存槑褰撳墠鑺傜偣杩樺瓨鍦ㄥ彟涓€涓浘骞胯矾鍒嗘敮銆?

            }
        }
        return flow;
    }

    int Maxflow(int s,int t)//涓昏繃绋?
    {
        this->s=s,this->t=t;
        int flow=0;
        while(bfs())
        {
            memset(cur,0,sizeof(cur));
            flow+=dfs(s,INF);
        }
        return flow;
    }
  }dinc;

int u,v,w;
char stmp[220];
int main()
{
    fuckio
    ww(~scanf("%d%d",&M,&N)){
        dinc.init();
        rep(i,M){
            scanf("%d%d%d",&u,&v,&w);
            dinc.addedge(u,v,w);
        }
        pc(dinc.Maxflow(1,N));
    }
}