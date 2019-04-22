#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <algorithm>
#include <queue>
#include <stdio.h>
#define INF 0x7f7f7f7f
using namespace std;

const int maxn = 110020;
const int maxm = 1100020;
int ct = 0;
int ans;
int n,m,s,t,k;
int head[maxn];
int dis[maxn];
int stt[maxn];

struct Edge{
    int v , w ,next;
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
       // cout << t.x << endl;
        if(dis[t.x] != t.dis)continue;
        for(int i = head[t.x];~i;i = edge[i].next)
        {
            int to = edge[i].v;
            if(dis[t.x] + edge[i].w < dis[to]){
                dis[to] = dis[t.x] + edge[i].w;
                Q.push((node){to,dis[to]});
            }
        }
    }

}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&k)){
        init((k+1)*(n));
        scanf("%d%d",&s,&t);
        for(int i = 0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d" , &u,&v,&w);
            for(int j = 0;j<=k;j++)
            {
                addedge(u + j*n , v+j*n , w);
                addedge(v + j*n , u+j*n , w);
                if(j){

                    addedge(u+(j-1)*n , v+j*n , 0);
                    addedge(v+(j-1)*n , u+j*n , 0);
                }
            }
        }

        dijk(s);
        int mn = INF;

        for(int i = 0;i<=k;i++){
            //cout << dis[t + i*n] << endl;
            mn = min(mn , dis[t + i*n]);
        }
        printf("%d\n" , mn);

    }
}
