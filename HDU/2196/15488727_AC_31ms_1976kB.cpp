#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
#define Del(a,b) memset(a,b,sizeof(a))
const int N = 10100;
 
struct Node
{
    int to;
    int cap;
};
vector<Node> v[N];
int dp[N][4]; ///dp[i][0] 为从下往上最短距离 dp[i][1] 为从下往上此短距离 dp[i][2] 为从经过root最短距离
int n;
void dfs1(int father)
{
    int mast=0,maer=0;
    for(int i=0;i<v[father].size();i++)
    {
        Node child=v[father][i];
        dfs1(child.to);
        int cost=dp[child.to][0]+child.cap;
        if(cost>=mast)
        {
            maer=mast;
            mast=cost;
        }
        else if(cost>maer)
        {
            maer = cost;
        }
    }
    dp[father][0]=mast;
    dp[father][1]=maer;
}
void dfs2(int father)
{
    for(int i=0;i<v[father].size();i++)
    {
        Node child=v[father][i];
        dp[child.to][2]=max(dp[father][2],dp[child.to][0]+child.cap==dp[father][0]?dp[father][1]:dp[father][0])+child.cap;
        //dp更新从父节点过来的最大值
        dfs2(child.to);
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=2;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            Node tmp;tmp.cap = y;
            tmp.to=i;
            v[x].push_back(tmp);
        }
        Del(dp,0);
        dfs1(1);
        dp[1][2]=0;
        dfs2(1);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            printf("%d\n",max(dp[i][0],dp[i][2]));
        }
        for(int i=1;i<=n;i++)
            v[i].clear();
    }
    return 0;
}