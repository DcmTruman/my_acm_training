#include<iostream>
#include<algorithm>
#include<string.h>
#define Fill(a,b) memset(a,(b),sizeof(a))
using namespace std;

typedef long long ll;



const int maxn = 5e4+5;
int n, cnt, head[maxn], k, vis[maxn], root, maxx, dis[maxn];
int num, tot, siz[maxn], mv[maxn];
int a[maxn];
struct node {
    int to, w, next;
} e[maxn<<1];

void add(int u, int v, int w)
{
    e[cnt] = (node){v,w,head[u]};
    head[u] = cnt++;
}

void getroot(int u, int fa)
{
    siz[u] = 1, mv[u] = 0;
    for (int i = head[u]; ~i; i = e[i].next) {
        int to = e[i].to;
        if (to == fa || vis[to]) continue;
        getroot(to, u);
        siz[u] += siz[to];
        mv[u] = max(mv[u], siz[to]);
    }
    mv[u] = max(mv[u], tot - siz[u]);
    if (mv[u] < mv[root]) root = u;
}
int dp[1030]; //这个不能开太大,否则会T.
void getdis(int u,int fa,int dep)
{
    //cout<<dep<<endl;
    dp[dep]++;
    dis[++num] = dep;
    for (int i = head[u]; ~i; i = e[i].next) {
        int to = e[i].to;
        if (to == fa || vis[to]) continue;
        getdis(to, u, dep | (1 << a[to]));
    }
}
ll ans;

ll cal(int u,int f)
{
    num = 0; Fill(dp,0);
    getdis(u,0,f | (1 << a[u]));
    for(int i=0;i<k;i++){
        for(int j = 0 ; j < (1<<k) ; j++) {
            if(!((1<<i) & j)) dp[j] += dp[j | (1 << i)];
        }
    }
    ll res = 0;
    for(int i=1;i<=num;i++){
        int tmp = dis[i];
        tmp ^= (1<<k)-1;
        res += dp[tmp];

		//cout<<"Debug :"<<num<<" "<<dp[tmp]<<endl;
    }
    return res;
}

void work(int u)
{
    vis[u] = 1;
    ans += cal(u, 0);
    for (int i = head[u]; ~i; i = e[i].next) {
        int to = e[i].to;
        if (vis[to]) continue;
        ll tmp = cal(to, 1 << a[u]);
        ans -= tmp;
        root = 0;tot = siz[to];
        //mv[root=0] = tot = siz[to];
        getroot(to, 0);
        work(root);
    }
}

int main()
{
    while(~scanf("%d%d",&n,&k)){
        cnt = 0 ; Fill(head,-1); Fill(vis,0);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            a[i]--;
        }
        for (int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d",&u,&v);
            add(u, v, 0); add(v, u, 0);
        }
        ans = 0;
        mv[root=0] = tot = n;
        getroot(1, 0);
        work(root);
        cout << ans << endl;
    }
}