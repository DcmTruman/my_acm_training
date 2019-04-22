#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <vector>
#define INF 0x7f7f7f7f
#define ll long long

using namespace std;

const int maxn = 100020;
const int maxm = 200020;
const int mod  = 1e9+7;
queue<int>Q;
vector<int>V;
ll head[maxn] , du[maxn];
ll aa[maxn],bb[maxn];
ll sum , dp[maxn];
ll ct = 0;
ll m,n,u,v,w;
void init(ll n)
{
    for(int i = 0;i<=n;i++){
        head[i] = -1;
        du[i] = 0;
        dp[i] = 0;
    }
    while(!Q.empty())Q.pop();
    V.clear();
    sum = 0;
    ct = 0;

}

struct _edge{
    int v;
    int next;
}edge[maxm];

void addedge(int u,int v)
{
    du[v] ++;
    edge[ct].v = v;
    edge[ct].next = head[u];
    head[u] = ct++;
}

void topu()
{
    for(int i = 1;i<=n;i++)
    {
        if(du[i] == 0)Q.push(i);
    }
    while(!Q.empty())
    {
        int t = Q.front();
        V.push_back(t);
        Q.pop();
        for(int i = head[t];~i;i = edge[i].next)
        {
            int to = edge[i].v;
            du[to]--;
            if(du[to] == 0)Q.push(to);
        }
    }

}


int main()
{
    while(~scanf("%lld%lld",&n,&m))
    {
        init(n);
        for(int i = 1;i<=n;i++)
        {
            scanf("%lld%lld",&aa[i],&bb[i]);
        }
        for(int i = 0;i<m;i++)
        {
            scanf("%lld%lld",&u,&v);
            addedge(u,v);
        }
        topu();
        int sz = V.size();
        for(int i = 0;i<sz;i++)
        {
            ll now = V[i];
            for(int j = head[now];~j;j = edge[j].next)
            {
                ll to = edge[j].v;
                dp[to] = (((dp[to] + dp[now])%mod) +aa[now])%mod;//每新增一条路i~j的路，对j来说都会有aa[i]的贡献
            }
        }
        for(int i = 1;i<=n;i++)
        {
            sum = (sum + (dp[i] * bb[i])%mod)%mod;
        }

        printf("%lld\n",sum);

    }
    return 0;
}
