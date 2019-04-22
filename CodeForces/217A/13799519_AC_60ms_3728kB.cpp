#include<iostream>

using namespace std;

typedef struct _node{
    int x,y;
}node;

int fa[120];

void init()
{
    for(int i = 0;i<120;i++)
    {
        fa[i] = i;
    }
}

int find(int x)
{
    return (x!=fa[x])?fa[x] = find(fa[x]):fa[x];
}

bool join(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx!=fy){
        fa[fx] = fy;
        return true;
        }
    return false;
}

node N[120];

int main()
{
    int n;
    while(cin>>n)
    {
        init();
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            cin >> N[i].x>>N[i].y;
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(N[i].x == N[j].x || N[i].y == N[j].y)
                {
                    if(join(i,j))ans++;   
                }
            }
        }
        cout<<n-1-ans<<endl;
    }
}