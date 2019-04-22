#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int GCD(int a,int b)
{
    if (a % b == 0)return b;
    return GCD(b , a % b);
}
int ggg[100000];
int main()
{
    int x,y,num = 0,n;
    cin>>x>>y;
    int g = GCD(x,y);
    for(int i=1;i<=sqrt(g);i++)
    {
        if(g%i == 0)
        {
            ggg[num++] = i;
            ggg[num++] = g/i;
        }
    }
    sort(ggg,ggg+num);
    cin>>n;
    while(n--)
    {
        int a,b,pos = 0;
        cin>>a>>b;
        for(int i=0;i<num;i++)
        {
            if(ggg[i]>b)
            {
                pos = i-1;
                break;
            }
            else
            {
                pos = i;
            }
        }
        if(ggg[pos]<a)cout<<"-1"<<endl;
        else cout<<ggg[pos]<<endl;
    }
}