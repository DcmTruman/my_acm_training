#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int Map[1020][1020];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int Visit[1020][1020] ;
int m,n,q;
typedef struct _p
{
    int x,y,t,d;
}pos;
bool check(pos a)
{
    if(a.x<1||a.y<1||a.x>m||a.y>n)return false;
    return true;
}
queue<pos>Q;
int main()
{
    cin>>m>>n;
    while(m&&n)
    {
        
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                cin>>Map[i][j];
            }
        }
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if((Map[x1][y1]!=Map[x2][y2])||(Map[x1][y1]==0)||(Map[x2][y2]==0))
            {
                cout<<"NO"<<endl;
            }
            else
            {
                while(!Q.empty())Q.pop();
                for(int k=0;k<n+5;k++)
                {
                    for(int q=0;q<m+5;q++)Visit[k][q]=99;
                }
                pos end = {x2,y2,0,0};
                int flag = 0;
                for(int i=0;i<4;i++)
                {
                    pos t = {x1,y1,0,i};
                    Q.push(t);
                }
                while(!Q.empty())
                {
                    pos now = Q.front();
                    Q.pop();
                    if(now.x == end.x&&now.y == end.y&&now.t<=2)
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        for(int i = 0;i<4;i++){
                            pos temp;
                            temp.x = now.x+dir[i][0];
                            temp.y = now.y+dir[i][1];
                            if(now.d == i)
                            {
                                temp.d = now.d;
                                temp.t = now.t;
                            }
                            else {
                                temp.d = i;
                                temp.t = now.t+1;
                            }
                            if(check(temp)&&(Map[temp.x][temp.y] == 0||(temp.x==end.x&&temp.y == end.y))
                               &&Visit[temp.x][temp.y]>=temp.t)
                            {
                                Visit[temp.x][temp.y] = temp.t;
                                Q.push(temp);
                            }
                        }
                    }
                }
                if(flag)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
        cin>>m>>n;
    }
}