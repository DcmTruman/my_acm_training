#include<iostream>
#include <algorithm>
#include<queue>
#include<stdio.h>
#define INF 0x3fffffff
using namespace std;
int n,m;
int map[1020][1020];
int dis[1020];
bool visit[1020];
void djks(int s)
{
    for(int i=1;i<=n;i++)
        dis[i] = map[s][i];
    visit[s] = true;
    dis[s] = 0;
    for(int i=1;i<=n;i++)
    {
        int min = INF;
        int pos = s;
        for(int j = 1;j<=n;j++)
        {
            if(!visit[j]&&dis[j]<min)
            {
                min = dis[j];
                pos = j;
            }
        }
        if(min == INF)break;
        visit[pos] = true;
        for(int j = 1;j<=n;j++)
        {
            if(!visit[j]&& dis[pos]+map[pos][j]<dis[j])
            {
                dis[j] = dis[pos]+map[pos][j];
            }
        }
    }
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            map[i][j] = INF;
    int a,b,c;
    for(int i = 0;i<m;i++)
    {
        cin>>a>>b>>c;
        map[a][b] = min(map[a][b],c);
        map[b][a] = map[a][b];
    }
    djks(1);
    cout<<dis[n]<<endl;
    
}
