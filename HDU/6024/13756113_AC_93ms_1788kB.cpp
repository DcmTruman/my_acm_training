#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 3010;
const long long MM = 999999999999;
struct node
{
    long long x,c;
    bool operator < (node & a)
    {
        return this->x < a.x;
    }
    node():x(0),c(0){}
}nodes[maxn];

long long dp[maxn][2];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%I64d%I64d",&nodes[i].x,&nodes[i].c);
        }
        sort(nodes,nodes+n);
        dp[0][1] = nodes[0].c;
        dp[0][0] = MM;
        for(int i=1;i<n;i++)
        {
            dp[i][1] = nodes[i].c + min(dp[i-1][0],dp[i-1][1]);
            dp[i][0] = MM;
            long long t = 0;
            for(int j=i-1;j>=0;j--)
            {
                t += (i - j) * (nodes[j+1].x - nodes[j].x);
                dp[i][0] = min(dp[i][0],dp[j][1] + t);
            }
        }
        printf("%I64d\n",min(dp[n-1][0],dp[n-1][1]));
    }
    return 0;
}