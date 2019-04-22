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
const int maxm = 1000020;
const int mod  = 142857;
vector<int>V;
ll u,v,w,head[maxn],ct,du2[maxn],du[maxn];
ll dp[maxn];
ll n,m,k;
struct _edge{
    int v,next;
}edge[maxm];

void init(int n)
{
    ct = 0;
    for(int i = 0;i<=n;i++){
        du[i] = du2[i] = 0;
        head[i] = -1;
        dp[i] = 0;
    }
}

void addedge(int u,int v)
{
    du2[v] = du[v] = du[v] + 1;
    edge[ct].v = v;
    edge[ct].next = head[u];
    head[u] = ct++;
}

void topu()
{
    queue<int>Q;
    V.clear();
    for(int i = 1;i<=n;i++){
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
            du2[to]--;
            if(du2[to] == 0)Q.push(to);
        }
    }
}

int main()
{
    while(~scanf("%lld%lld%lld",&n,&m,&k))
    {
        init(n);
        for(int i = 0;i<k;i++){
            scanf("%lld",&u);
            dp[u]++;
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
            int now = V[i];
            for(int j = head[now];~j;j=edge[j].next)
            {
                int to = edge[j].v;
                dp[to] = (dp[to] + dp[now])%mod;
            }
        }
        ll ans = 0;
        for(int i = 1;i<=n;i++)ans = (ans + dp[i])%mod;
        printf("%lld\n",ans);
    }
}
