#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define debug(x); cout << __LINE__ << ": name : " << #x << " "<<x<<endl;
using namespace std;

const int maxn = 2000000 + 20;

int fa[maxn];
int m,n,x,y,xx,yy,a,b;
bool flag;
void init()
{
    for(int i = 0;i<maxn;i++)fa[i] = i;
}

int find(int x)
{
    return (fa[x] == x)?fa[x] : fa[x] = find(fa[x]);
}

int main()
{
    int T;scanf("%d", &T);
    for(int tt = 1;tt<=T;tt++)
    {
        if(tt != 1)printf("\n");
        flag = true;
        scanf("%d%d" , &n , &m);
        init();
        for(int i = 0;i<m;i++)
        {
            scanf("%d%d" , &a,&b);
            x = find(a);y = find(b);
            xx = find(a + n);yy = find(b +n);
            if(x != y && xx != yy){
                fa[x] = yy;
                fa[y] = xx;
            }else {
                flag = false;
            }
        }
        if(!flag)printf("Scenario #%d:\nSuspicious bugs found!\n" , tt);
        else printf("Scenario #%d:\nNo suspicious bugs found!\n" , tt);
    }
}


