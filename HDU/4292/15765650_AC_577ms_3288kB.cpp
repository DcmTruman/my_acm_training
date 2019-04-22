#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define N 850
#define M 201000
#define INF 0x3f3f3f3f
using namespace std;

struct EDGE{
    int v, cap, nt;
};

int first[N];
EDGE g[M];
int cnt;
int n, f, d;

void addEdge(int u, int v, int cap){
    g[cnt].v=v;
    g[cnt].cap=cap;
    g[cnt].nt=first[u];
    first[u]=cnt++;
    
    g[cnt].v=u;
    g[cnt].cap=0;
    g[cnt].nt=first[v];
    first[v]=cnt++;
}

int ans, ss;

queue<int>q;
int dist[N];

bool bfs(){
    memset(dist, 0, sizeof(dist));
    dist[0]=1;
    q.push(0);
    while(!q.empty()){
          int u=q.front();
        q.pop();
        for(int e=first[u]; ~e; e=g[e].nt){
               int v=g[e].v;
            int cap=g[e].cap;
            if(!dist[v] && cap>0){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }    
    }
    if(dist[ss+1]==0) return false;
    return true;
}

int dfs(int u, int flow){
    int ff;
    if(u==ss+1) return flow;
    for(int e=first[u]; ~e; e=g[e].nt){
        int v=g[e].v;
        int cap=g[e].cap;    
        if(dist[v]==dist[u]+1 && cap>0 && (ff=dfs(v, min(cap, flow)))){
            g[e].cap-=ff;
            g[e^1].cap+=ff;
            return ff;
        }
     }
    dist[u]=-1;//表示u节点不能到达汇点！ 
    return 0;
}

void Dinic(){
    ans=0;
    int d;
    while(bfs())
         while(d=dfs(0, INF))
            ans+=d;
}

int main(){
    while(scanf("%d%d%d", &n, &f, &d)!=EOF){
        ss=2*n+f+d;
        cnt=0;
        memset(first, -1, sizeof(first));
        for(int i=1; i<=f; ++i){//源点到吃的建一条有向边，最大流量为吃的的数量 
            int x;
            scanf("%d", &x);
            addEdge(0, i, x);
        }

        for(int i=1; i<=d; ++i){//喝的到汇点建一条有向边，最大流量为喝的的数量
            int x;
            scanf("%d", &x);
            addEdge(n*2+f+i, ss+1, x);
        }
        for(int i=1; i<=n; ++i){//吃的到人建一条有向边，最大流量为1 
            getchar();
            for(int j=1; j<=f; ++j){
                char ch;
                scanf("%c", &ch);
                if(ch=='Y')
                    addEdge(j, f+i, 1);
            }
        }

        for(int i=1; i<=n; ++i){//人到喝的建一条有向边，最大流量为1 
            addEdge(f+i, n+f+i, 1);//人属于节点容量，将人进行拆分，因为每一个人只能有一种选择！ 
            getchar();
            for(int j=1; j<=d; ++j){
                char ch;
                scanf("%c", &ch);
                if(ch=='Y')
                    addEdge(n+f+i, f+n*2+j, 1);
            }
        }

        Dinic();
        printf("%d\n", ans);
    }
}