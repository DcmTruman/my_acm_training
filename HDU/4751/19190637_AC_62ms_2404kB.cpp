#include <iostream>
#include <stdio.h>

using namespace std;

const int maxn = 1020;
int head[maxn];
int color[maxn];
bool know[maxn][maxn];
bool flag;
int n , cnt , now , x;
void init(){
    for(int i = 0;i<maxn;i++){
        head[i] = -1;
        color[i] = 0;
        for(int j = 0;j<maxn;j++){
            know[i][j] = 0;
        }
    }
    cnt = 0;
}

struct Edge{
    int to,next;
}edge[maxn];

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
    while(~scanf("%d",&n))
    {
        init();
        now = 1;
        while(1)
        {
            scanf("%d",&x);
            while(x)
            {

                know[now][x] = 1;
                scanf("%d",&x);
            }
            if(now == n)break;
            now++;
        }
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                if(!know[i][j] || !know[j][i]){
                    addedge(i,j);
                    addedge(j,i);
                }
            }
        }
        flag = true;

        for(int i = 1;i<=n;i++){
            if(!color[i]){
                if(!dfs(i,1)){
                    flag = false;
                    break;
                }
            }
        }
        printf((flag)?"YES\n":"NO\n");


    }
}
