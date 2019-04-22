#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
 
int dx[6] = {0,0,-1,1,0,0};
int dy[6] = {0,0,0,0,1,-1};
int dz[6] = {1,-1,0,0,0,0};
 
char Map[40][40][40];
int vis[40][40][40], L, R, C;
 
struct node
{
    int x, y, z;
    int time;
}st, ed;
queue<node> q;
 
bool check(int x, int y, int z) 
{
    if(x >= 1 && x <= L && y >= 1 && y <= R && z >= 1 && z <= C)
        return true;
    return false;
}
 
int BFS()
{
    int x, y, z, t, i;
    while(!q.empty())
    {
        node tmp = q.front();
        q.pop();
        x = tmp.x;
        y = tmp.y;
        z = tmp.z;
        t = tmp.time;
        for(i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(!vis[nx][ny][nz] && Map[nx][ny][nz] != '#' && check(nx,ny,nz))
            {
                if(nx == ed.x && ny == ed.y && nz == ed.z)
                    return t+1;
                vis[nx][ny][nz] = 1;
                node temp;
                temp.x = nx;
                temp.y = ny;
                temp.z = nz;
                temp.time = t + 1;
                q.push(temp);
            }
        }
    }
    return -1;
}
 
int main()
{
    while(~scanf("%d%d%d",&L, &R, &C) && (L + R + C))
    {
        memset(vis,0,sizeof(vis));
        int i, j, k;
        for(i = 1; i <= L; i++)
        {
            for(j = 1; j <= R; j++)
            {
                for(k = 1; k <= C; k++)
                {
 
                    cin>>Map[i][j][k];
                    if(Map[i][j][k] == 'S')
                    {
                        st.x = i, st.y = j, st.z = k;st.time = 0;
                        q.push(st);
                         vis[i][j][k] = 1;
                    }
                    else if(Map[i][j][k] == 'E')
                        ed.x = i, ed.y = j, ed.z = k;
                }
            }
        }
        int ans = BFS();
        if(ans == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n",ans);
        while(!q.empty())  q.pop();
    }
    return 0;
}