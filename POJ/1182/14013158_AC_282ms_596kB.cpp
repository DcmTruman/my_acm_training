#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

const int maxn = 50020;

int fa[maxn],val[maxn];//val数组表示每个节点和其father的关系，0表示同类，1表示被吃，2表示吃
int n,k;
void init()
{
    for(int i = 0;i<n;i++)
    {
        fa[i] = i;
        val[i] = 0;
    }
}
int find(int x)
{
    if(fa[x] == x)return fa[x];
    else
    {
        int temp = fa[x];
        fa[x] = find(fa[x]);
        val[x] = (val[x]+val[temp])%3;
        return fa[x];
    }
}
void merge(int x,int y,int t)
{
    int fx = find(x);
    int fy = find(y);
    if(fx!=fy)
    {
        fa[fx] = fy;
        val[fx] = (val[y]-val[x]+t+3)%3;        
    }   
}

bool isOK(int x,int y,int t)
{
    if(x>n||y>n)return false;
    if(x == y&&t!=0)return false;
    if(find(x) == find(y))
    {
        return (val[x]-val[y]+3)%3 == t;
    }
    else return true;
}

int main()
{
    scanf("%d%d",&n,&k);
    int ans = 0;
    int x,y,t;
    init();
    while(k--)
    {
        scanf("%d%d%d",&t,&x,&y);
        if(isOK(x,y,t-1))
        {
            merge(x,y,t-1);
        }
        else ans++;
    }
    cout<<ans<<endl;
}