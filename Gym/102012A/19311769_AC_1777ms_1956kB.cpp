#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <algorithm>
#include <queue>
#include <stdio.h>
#define INF 0x7f7f7f7f
#define ull unsigned long long
using namespace std;
const int maxn = 100020;
const int MOD = 1e9+7;

ull k1,k2;
int n,m;
int fa[maxn];

void init(int n)
{
    for(int i = 0;i<=n;i++)fa[i] = i;
}
int find(int x)
{
    return (fa[x] == x)?x : fa[x] = find(fa[x]);
}
struct Edge{
    int u,v;
    ull w;
}edge[maxn];

unsigned long long xors()
{
    ull k3=k1,k4=k2;
    k1=k4;
    k3^=k3<<23;
    k2=k3^k4^(k3>>17)^(k4>>26);
    return k2+k4;
}

void gen()
{
    //scanf("%d%d%llu%llu" , &n,&m,&k1,&k2);
    scanf("%d%d%llu%llu",&n,&m,&k1,&k2);
    //cin >> n >> m >>k1 >>k2;
    for(int i = 1;i<=m;i++)
    {
        edge[i].u = xors() % n + 1;
        edge[i].v = xors() % n + 1;
        edge[i].w = xors();
    }
}

bool cmp(Edge a,Edge b)
{
    return a.w < b.w;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        gen();
        init(n);
        int ct = 0;
        ull sum = 0;
        sort(edge+1,edge+1+m,cmp);
        for(int i = 1;i<=m;i++)
        {
            int fx = find(edge[i].u);
            int fy = find(edge[i].v);
            if(fx != fy){
                ct ++;
                fa[fx] = fy;
                sum = (sum + edge[i].w)%MOD;
            }
        }
        if(ct != n-1)printf("0\n");
        else printf("%llu\n" , sum);
    }
}
