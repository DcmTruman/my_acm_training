#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define debug(x); cout << __LINE__ << ": name : " << #x << " "<<x<<endl;
using namespace std;

const int maxn = 1000000 + 20;

int fa[maxn];
bool vis[maxn];
bool flag;
int cnt,a,b,tt,mx;
void init()
{
    for(int i = 0;i<maxn;i++)fa[i] = i , vis[i] = false;
    flag = true;
    cnt = 0;
}

int find(int x)
{
    return (fa[x] == x)?fa[x] : fa[x] = find(fa[x]);
}

bool merge(int a , int b)
{
    int xx = find(a) , yy = find(b);
    if(yy != b || xx == yy)return false;
    fa[yy] = xx;
    return true;
}

int main()
{
    tt = 1;
    init();
    while(~scanf("%d%d" , &a , &b)){
        if(a == -1 && b == -1)break;
        mx = max(max(mx , a) , b);
        if(a == 0 && b == 0){
            for(int i = 1;i<=mx ;i++){
                if(vis[i] && fa[i] == i)cnt ++;
                if(cnt > 1)flag = false;
            }

            if(!flag)printf("Case %d is not a tree.\n", tt++);
            else printf("Case %d is a tree.\n", tt++);
            init();
            continue;
        }
        vis[a] = vis[b] = true;
        if(!merge(a,b))flag = false;
    }
}


