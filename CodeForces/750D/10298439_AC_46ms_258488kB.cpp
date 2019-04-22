#include<iostream>

using namespace std;
bool visit[320][320];
bool boom[320][320][4][4][32][5]={false,};
int t[32];
int ans = 0;
int n;
typedef struct _F
{
    int x,y;
}pos;

void dfs(pos now,pos dir,int depth)
{
    
    if(depth>n)return;
    if(boom[now.x][now.y][dir.x+1][dir.y+1][depth][t[depth]])
    {
        return;
    }
    boom[now.x][now.y][dir.x+1][dir.y+1][depth][t[depth]] = true;
    for(int i=0;i<t[depth];i++)
    {
        now.x += dir.x;
        now.y += dir.y;
        if(!visit[now.x][now.y])
        {
            visit[now.x][now.y] = true;
            ans++;
        }
    }

    if(dir.x&&dir.y)
    {
        pos tdir = {dir.x,0};
        dfs(now,tdir,depth+1);
        tdir = {0,dir.y};
        dfs(now,tdir,depth+1);
    }
    else if(dir.x == 0)
    {
        pos tdir = {1,dir.y};
        dfs(now,tdir,depth+1);
        tdir = {-1,dir.y};
        dfs(now,tdir,depth+1);
    }
    else if(dir.y == 0)
    {
        pos tdir = {dir.x,1};
        dfs(now,tdir,depth+1);
        tdir = {dir.x,-1};
        dfs(now,tdir,depth+1);
    }
    
}
int main()
{
    cin>>n;
    for(int i =1;i<=n;i++)
    {
        cin>>t[i];
    }
    pos start = {152,151};
    pos dir = {-1,0};
    dfs(start,dir,1);
    cout<<ans<<endl;
}