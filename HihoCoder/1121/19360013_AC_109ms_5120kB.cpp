#include <iostream>
#include <stdio.h>

using namespace std;

const int maxn = 10020;
const int maxm = 80020;
int head[maxn];
int color[maxn];
int n,m;
bool flag;
int  cnt , now , x;
void init(int n){
    for(int i = 0;i<=n;i++){
        head[i] = -1;
        color[i] = 0;
    }
    cnt = 0;
}

struct Edge{
    int to,next;
}edge[maxm];

void addedge(int u,int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

bool dfs(int now,int col)
{
    color[now] = col;
    for(int i = head[now];~i;i = edge[i].next){
        int to = edge[i].to;
        if(color[now] == color[to])return false;
        if(!color[to]){
            if(!dfs(to,3-col))return false;
        }
    }
    return true;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        init(n);
        for(int i = 0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        flag = true;
        for(int i = 1;i<=n;i++)
        {
            if(!color[i]){
                if(!dfs(i,1)){
                    flag = false;
                    break;
                }
            }
        }
        printf((flag)?"Correct\n":"Wrong\n");

    }
}
