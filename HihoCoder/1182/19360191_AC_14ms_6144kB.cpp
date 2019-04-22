#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

const int maxn = 400020;
const int maxm = 400020;
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
            dfs(to);
        }
    }
    s.push(now&1);
}
int main()
{
    scanf("%d" , &n);
    if(n == 1)
    {
        printf("01\n");
        return 0;
    }
    init((1<<n));
    for(int i = 0;i< (1 << n -1);i++)
    {
        int j = (i << 1) & ((1 << (n-1)) - 1);
        addedge(i,j);
        addedge(i,j+1);
    }
    dfs(0);
    while(s.size()>1)
    {
        printf("%d",s.top());
        s.pop();
    }
    printf("\n");

}
