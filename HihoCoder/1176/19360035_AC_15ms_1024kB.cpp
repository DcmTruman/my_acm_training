#include <iostream>
#include <stdio.h>

using namespace std;

const int maxn = 10020;
const int maxm = 80020;
int head[maxn];
int color[maxn];
int du[maxn];
int n,m;
bool flag;
int u,v;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        du[u] ++;
        du[v] ++;
    }
    flag = false;
    int cnt = 0;
    for(int i = 1;i<=n;i++)
    {
        if(du[i]&1 ){
            cnt ++;
        }
    }
    if(cnt == 2 || cnt == 0)flag = true;
    printf((flag)?"Full\n":"Part\n");
}
