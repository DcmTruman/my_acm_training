#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

typedef struct _node{
    int x;
    int y;
    int time;
    bool operator<(const  _node B)const
    {
        return time>B.time;
    }
    _node(int x,int y):x(x),y(y){}
    _node(){}
}node;

char MM[205][205];
bool visit[205][205];

int m,n;
node start;
int ans = -1;
int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};

bool isOK(int x,int y)
{
    if(x<0||y<0||x>=n||y>=m)return false;
    return true;
}

void BFS()
{
    priority_queue<node>Q;
    node t;
    Q.push(start);
    while(!Q.empty())
    {
        t = Q.top();
        Q.pop();
        for(int i = 0;i<4;i++)
        {
            int xx = t.x+mx[i];
            int yy = t.y+my[i];
            if(isOK(xx,yy)&&!visit[xx][yy]&&MM[xx][yy]!='#')
            {
                node temp(xx,yy);
                if(MM[xx][yy] == 'r')
                {
                    ans = t.time+1;
                    return;
                }
                else if(MM[xx][yy] == '.')
                {
                    temp.time = t.time+1;
                }
                else if(MM[xx][yy] == 'x')
                {
                    temp.time = t.time+2;
                }
                visit[xx][yy] = true;
                Q.push(temp);
            }
        }
    }    
}
int main()
{
    while(cin>>n>>m)
    {
        memset(visit,0,sizeof(visit));
        ans = -1;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                cin>>MM[i][j];
                if(MM[i][j] == 'a')
                {
                    start.x = i;
                    start.y = j;
                    start.time = 0;
                }
            }
        }
        BFS();
        if(ans == -1)cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
        else cout<<ans<<endl;
    }
}