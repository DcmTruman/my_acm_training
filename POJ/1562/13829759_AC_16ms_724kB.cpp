#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

typedef struct _node{
    int x,y;
}node;

int m,n,ans = 0;
bool visit[120][120];
bool MM[120][120];
queue<node>Q;
node temp;
int mx[8] = {1,0,-1,0,1,1,-1,-1};
int my[8] = {0,1,0,-1,1,-1,1,-1};
bool isOK(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m)return false;
    return true;
}
void init()
{
    ans = 0;
    memset(visit,0,sizeof(visit));
    while(!Q.empty())Q.pop();
    memset(MM,0,sizeof(MM));
}

void bfs(node start)
{
    while(!Q.empty())Q.pop();
    visit[start.x][start.y] = true;
    Q.push(start);
    while(!Q.empty())
    {
        node t = Q.front();
        Q.pop();
        for(int i = 0;i<8;i++)
        {
            int xx = t.x + mx[i];
            int yy = t.y + my[i];
            if(isOK(xx,yy)&&MM[xx][yy]&&!visit[xx][yy])
            {
                visit[xx][yy] = true;
                temp.x = xx;
                temp.y = yy;
                Q.push(temp);
            }
        }
    }
}
char ccc;
int main()
{
   while(cin>>n>>m&&(m||n)) 
   {
       init();
       for(int i = 0;i<n;i++)
       {
           for(int j = 0;j<m;j++)
           {
               cin>>ccc;
               if(ccc == '*')
               {
                   MM[i][j] = false;
               }
               else
               {
                   MM[i][j] = true;
               }
           }
       }
       for(int i = 0;i<n;i++)
       {
           for(int j = 0;j<m;j++)
           {
               if(!visit[i][j]&&MM[i][j])
               {
                   
                   ans++;
                   node start;
                   start.x = i;
                   start.y = j;
                   bfs(start);
               }
           }
       }
       cout<<ans<<endl;
   }
}