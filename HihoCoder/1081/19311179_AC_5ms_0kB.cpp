#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <algorithm>
#include <queue>
#define INF 0x7f7f7f7f
using namespace std;

const int maxn = 10020;

int ct = 0;
int ans;
int n,m,s,t;
int head[maxn];
int dis[maxn];
struct {
    int v , w , next;
}edge[2*maxn];

struct node{
    int x;
    int dis;
    bool operator < (const node b)const{
        return dis > b.dis;
    }
};


void init(int n)
{
    for(int i = 0;i<=n;i++)head[i] = -1 ,dis[i] = INF ;
    ct = 0;
}

void addedge(int u,int v,int w)
{
    edge[ct].v = v;
    edge[ct].w = w;
    edge[ct].next = head[u];
    head[u] = ct++;
}

void dijk(int now)
{
    node st;
    st.x = now;
    st.dis = 0;
    dis[now] = 0;
    priority_queue<node>Q;
    Q.push(st);
    while(!Q.empty())
    {
        node t = Q.top();
        Q.pop();
        if(dis[t.x] != t.dis)continue;
        for(int i = head[t.x];~i;i = edge[i].next)
        {
            int to = edge[i].v;
            if(dis[t.x] + edge[i].w < dis[to]){
                dis[to] = dis[t.x] + edge[i].w;
                //cout << "to = " << to << " , dis[to] = " <<dis[to] << endl;
                Q.push((node){to , dis[to]});
            }
        }
    }

}
int main()
{
    int T;
    //cin >> T;
    //for(int tt = 1;tt<=T;tt++)
   // {
        cin >> n >> m >> s >>t;
        init(n);
        for(int i = 0;i<m;i++)
        {
            int u,v,w;cin >> u >> v >>w;
            addedge(u,v,w);
            addedge(v,u,w);
            //cout << "fuck" <<endl;
        }
        dijk(s);
        cout << dis[t] << endl;
   // }
}
