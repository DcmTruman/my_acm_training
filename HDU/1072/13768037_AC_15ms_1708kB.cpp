#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

typedef struct _node{
    int x,y,t,step;
}node;
queue<node>Q;

int T;
int N,M;
int map[10][10]; 
int ans = 0;
bool visit[10][10][10];
node start,ee;
int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
bool isOK(int x,int y)
{
    if(x<0||y<0||x>=N||y>=M)return false;
    return true;
}
void bfs()
{
    Q.push(start);
    visit[start.x][start.y][start.t] = true;
    while(!Q.empty())
    {
        node t = Q.front();
        Q.pop();
        if(t.t<=0)continue;
        if(t.x == ee.x&&t.y==ee.y)
        {
            if(ans == -1||ans>t.step)
            {
                ans = t.step;
            }           
        }
        if(map[t.x][t.y] == 4)
        {
            t.t = 6;
        }
        for(int i = 0;i<4;i++)
        {
           int xx = t.x+mx[i];
           int yy = t.y+my[i];
           if(isOK(xx,yy)&&!visit[xx][yy][t.t-1]&&map[xx][yy]!=0)
           {
               visit[xx][yy][t.t-1] = true;
               node temp;
               temp.x = xx;
               temp.y = yy;
               temp.t = t.t-1;
               temp.step = t.step+1;
               Q.push(temp);
           }  
        }
    }
}
int main()
{
    cin>>T;
    while(T--)
    {
        memset(visit,0,sizeof(visit));
        memset(map,0,sizeof(map));
        ans = -1;
        while(!Q.empty())Q.pop();
        cin>>N>>M;
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<M;j++)
            {
                cin>>map[i][j];                
                if(map[i][j] == 2)
                {
                    start.x = i;
                    start.y = j;
                    start.t = 6;
                    start.step = 0;
                }
                else if(map[i][j] == 3)
                {
                    ee.x = i;
                    ee.y = j;
                    ee.t = 6;
                    ee.step = 0;
                }
            }
        }
        bfs();
        cout<<ans<<endl;
    }    
}