#include<iostream>
#include <algorithm>
#include<queue>
#include<stdio.h>
#define INF 0x3fffffff
using namespace std;
int n,m;
int map[1020][1020];
int dis[1020][1020];
bool visit[1020];

void floyd()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j] = map[i][j];
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(i!=j&&j!=k&&i!=k)
                    dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
    
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)map[i][j] = 0;
            else map[i][j] = INF;
    int a,b,c;
    for(int i = 0;i<m;i++)
    {
        cin>>a>>b>>c;
        map[a][b] = min(map[a][b],c);
        map[b][a] = map[a][b];
    }
    floyd();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<"\n";
    }
}
