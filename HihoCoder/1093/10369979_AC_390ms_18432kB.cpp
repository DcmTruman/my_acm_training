#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 0x3fffffff
const int maxn = 1e5+20;
typedef struct _Edge{int from,to,dis;}Edge;
vector<Edge>edges;
vector<int>G[maxn];
bool inq[maxn];
int d[maxn];
int n,m,s,e,num = 0;
void addEdge(int u,int v,int w)
{
    G[u].push_back(num);
    Edge temp = {u,v,w};
    edges.push_back(temp);
    num++;
}
void SPFA(int s)
{
    queue<int>Q;
    for(int i=0;i<=n;i++)d[i] = INF;
    d[s] = 0;
    inq[s] = true;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for(int i=0;i<G[u].size();i++)
        {
            Edge e = edges[G[u][i]];
            if(d[u]<INF&&d[e.to]>d[u]+e.dis)
            {
                d[e.to] = d[u]+e.dis;
                if(!inq[e.to]){
                    Q.push(e.to);
                    inq[e.to] = true;
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m>>s>>e;
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        addEdge(a,b,c);
        addEdge(b,a,c);
    }
    SPFA(s);
    cout<<d[e]<<endl;
}