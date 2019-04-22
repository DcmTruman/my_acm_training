#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <algorithm>
#include <queue>
#include <stdio.h>
#define INF 0x7f7f7f7f
using namespace std;

const int maxn = 200020;
const int maxm = 200020;
int ct = 0;
int ans;
int n,m,s,t;
int head[maxn];
int dis[maxn];
int stt[maxn];
struct {
    int v , w ,next ,  sta;
}edge[2*maxm];

struct node{
    int x;
    int dis;
    bool operator < (const node b)const{
        return dis > b.dis;
    }
};


void init(int n)
{
    for(int i = 0;i<=n;i++)head[i] = -1 ,dis[i] = INF ,stt[i] = 0;;
    ct = 0;
}

void addedge(int u,int v,int w,int sta)
{
    edge[ct].v = v;
    edge[ct].w = w;
    edge[ct].next = head[u];
    edge[ct].sta = sta;
    head[u] = ct++;
}

void dijk(int now)
{
    node st;
    st.x = now;
    st.dis = 0;
    stt[now] = INF;
    dis[now] = 0;
    priority_queue<node>Q;
    Q.push(st);
    while(!Q.empty())
    {
        node t = Q.top();
        Q.pop();
       // cout << t.x << endl;
        if(dis[t.x] < t.dis)continue;
        for(int i = head[t.x];~i;i = edge[i].next)
        {
            int to = edge[i].v;

            if(stt[t.x] == INF && edge[i].w + dis[t.x] < dis[to]){
                dis[to] = edge[i].w + dis[t.x] ;
                stt[to] = edge[i].sta;
                //cout << "to = " << to << " , dis[to] = " <<dis[to] << endl;
                Q.push((node){to , dis[to]});
            }else if(edge[i].w + dis[t.x] + abs(stt[t.x] - edge[i].sta) < dis[to]){
                dis[to] = edge[i].w + dis[t.x] + abs(stt[t.x] - edge[i].sta);
                stt[to] = edge[i].sta;
                Q.push((node){to , dis[to]});
            }
        }
    }

}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        init(n);
        for(int i = 0;i<m;i++){
            int u,v,w,c;
            scanf("%d%d%d%d",&u,&v,&c,&w);
            addedge(u,v,w,c);
            addedge(v,u,w,c);
        }
        dijk(1);
        printf("%d\n",dis[n]);
    }
}
