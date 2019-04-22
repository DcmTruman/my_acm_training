#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 10020;

int fa[maxn];
int ct = 0;
int ans;
struct Edge{
    int u,v,w;
}edge[maxn];

void init(int n)
{
    ct = 0;
    ans = 0;
    for(int i = 0;i<=n;i++)
    {
        fa[i] = i;
    }
}

void addedge(int u,int v,int w)
{
    edge[ct].u = u;
    edge[ct].v = v;
    edge[ct].w = w;
    ct ++;
}
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}

int find(int x)
{
    return (fa[x] == x)?fa[x]:fa[x] = find(fa[x]);
}
int n,m;
int main()
{
    while(cin >> n && n){
        init(n);
        cin >> m;
        for(int i = 0;i<m;i++){
            int u,v,w;
            cin >> u >> v >> w;
            addedge(u,v,w);
        }
        sort(edge,edge+ct,cmp);
        for(int i = 0;i<ct;i++)
        {
            int u = edge[i].u , v = edge[i].v;
            int fx = find(u) , fy = find(v);
            if(fx != fy){
                fa[fx] = fy;
                ans += edge[i].w;
            }
        }
        cout << ans << endl;
    }
}
