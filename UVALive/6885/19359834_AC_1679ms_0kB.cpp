#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <vector>

#define INF 0x3f3f3f3f
#define ll long long

using namespace std;

const int maxn = 100020;
const int maxm = 500020;
const int mod  = 1e9+7;
int u,v,w,head[maxn],ct,inq[maxn] , dis[maxn],dis2[maxn];
int num[maxn];
int n,m;
struct _edge{
    int u,v,w,next;
}edge[maxm];

struct node{
    int x;
    int dis;
    bool operator < (const node &b)const {
        return dis > b.dis;
    }
};

void init(int n)
{
    ct = 0;
    for(int i = 0;i<=n;i++){
        dis[i] = dis2[i] = INF;
        head[i] = -1;
    }
}

void addedge(int u,int v,int w)
{
    edge[ct].u = u;
    edge[ct].v = v;
    edge[ct].w = w;
    edge[ct].next = head[u];
    head[u] = ct++;
}

void dijk(int now)
{
    node st;
    st.x = now;st.dis = 0;
    dis[now] = 0;
    priority_queue<node>Q;
    Q.push(st);
    while(!Q.empty())
    {
        node t = Q.top();
        Q.pop();
        if(t.dis != dis[t.x])continue;
        int u = t.x;
        for(int i = head[u];~i;i = edge[i].next)
        {
            int to = edge[i].v;
            if(dis[u] + edge[i].w < dis[to])
            {
                dis[to] = dis[u] + edge[i].w;
                Q.push((node){to,dis[to]});
            }
        }
    }
}

void spfa(int now)
{
    for(int i = 0;i<=n;i++)
    {
        inq[i] = false;
        dis[i] = INF;
        num[i] = 0;
    }
    dis[now] = 0;
    inq[now] = true;
    queue<int>Q;
    Q.push(now);
    while(!Q.empty())
    {
        int t = Q.front();
        Q.pop();
        inq[t] = false;
        num[t] ++;
        if(num[t] > n)return;
        for(int i = head[t];~i;i = edge[i].next)
        {
            int to = edge[i].v;
            int w = edge[i].w;
            if(w + dis[t] < dis[to])
            {
                dis[to] = w + dis[t];
                if(!inq[to])
                {
                    Q.push(to);
                    inq[to] = true;
                }
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init(n);
        for(int i = 0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        spfa(0);
        for(int i = 0;i<n;i++)dis2[i] = dis[i],dis[i] = INF;
        spfa(n-1);
        int ans = 0;
        for(int i = 0;i<ct;i++)
        {
            u = edge[i].u;
            v = edge[i].v;
            w = edge[i].w;
            if(dis2[u] + w + dis[v] == dis2[n-1] || dis[u] + w + dis2[v] == dis2[n-1] )ans += w;
        }
        printf("%d\n",ans);
    }
}
