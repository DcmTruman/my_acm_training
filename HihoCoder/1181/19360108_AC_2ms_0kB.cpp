#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

const int maxn = 10020;
const int maxm = 80020;
int head[maxn];
int n,m;
stack<int>s;
bool flag;
int du[maxn];
int u,v;
int ct;
void init(int n)
{
    for(int i = 0;i<=n;i++){
        head[i] = -1;
        ct = 0;
        du[i] = 0;
    }
}
struct _edge{
    int v,next,flag;
}edge[maxm];

void addedge(int u,int v)
{
    edge[ct].v = v;
    edge[ct].next = head[u];
    head[u] = ct++;
}

void dfs(int now)
{
    for(int i = head[now];~i;i = edge[i].next)
    {
        int to = edge[i].v;
        if(!edge[i].flag)
        {
            edge[i].flag = 1;
            edge[i^1].flag = 1;
            dfs(to);
        }
    }
    s.push(now);
}
int main()
{
    scanf("%d%d",&n,&m);
    init(n);
    for(int i = 0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
        du[u] ++;
        du[v] ++;
    }
    int pos = 1;
    for(int i = 1;i<=n;i++){
        if(du[i]&1){
            pos = i;
            break;
        }
    }
    dfs(pos);
    printf("%d",s.top());
    s.pop();
    while(!s.empty())
    {
        printf(" %d",s.top());
        s.pop();
    }
    printf("\n");
}
