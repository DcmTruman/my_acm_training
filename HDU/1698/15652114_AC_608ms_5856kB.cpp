#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define N 101000
#define Lson r<<1
#define Rson r<<1|1

struct node
{
    int L,R,e;
    bool is;
    int mid()
    {
        return (L+R)/2;
    }
    int len()
    {
        return R-L+1;
    }
}a[N*4];

void BuildTree(int r,int L,int R)
{
    a[r].L=L;
    a[r].R=R;
    a[r].e=1;
    if(L==R)
    {
        return;
    }
    BuildTree(Lson,L,a[r].mid());
    BuildTree(Rson,a[r].mid()+1,R);
}
int Qurry(int r)
{
    if(a[r].e!=-1)
        return a[r].len()*a[r].e;
    else
        return Qurry(Lson)+Qurry(Rson);
}
void Update(int r,int L,int R,int e)
{

    if(a[r].L==L && a[r].R==R)
    {
        a[r].e=e;
        return;
    }
    if(a[r].e!=-1)
    {
        a[Lson].e=a[Rson].e=a[r].e;
    }
    a[r].e=-1;
    if(R<=a[r].mid())
        Update(Lson,L,R,e);
    else if(L>a[r].mid())
        Update(Rson,L,R,e);
    else
    {
        Update(Lson,L,a[r].mid(),e);
        Update(Rson,a[r].mid()+1,R,e);
    }
}
int main()
{
    int T,n,m,i,t,x,y,e;
    scanf("%d",&T);
    t=1;
    while(T--)
    {
        scanf("%d",&n);
        BuildTree(1,1,n);
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {

            scanf("%d %d %d",&x,&y,&e);
            Update(1,x,y,e);
        }
        printf("Case %d: The total value of the hook is %d.\n",t++,Qurry(1));
    }
    return 0;
}