#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int f[52];
bool visit[1020];
int sg[1020];
void init()
{
    f[1] = 1;
    f[2] = 2;
    for(int i = 3;i<50;i++)
    {
        f[i] = f[i-2]+f[i-1];
    }
    sg[0] = 0;
    for(int i=1;i<=1000;i++)
    {
        memset(visit,0,sizeof visit);
        for(int j=1;i-f[j]>=0;j++)
        {
            visit[sg[i-f[j]]]=1;
        }
        for(int j=0;;j++)
        {
            if(!visit[j])
            {
                sg[i]=j;
                break;
            }
        }
    }
}
int main()
{
    init();
    int n,m,p;
    while(cin>>m>>n>>p)
    {
        if(!(m+n+p))break;
        if((sg[m]^sg[n]^sg[p]) == 0)cout<<"Nacci"<<endl;
        else cout<<"Fibo"<<endl;
    }
}