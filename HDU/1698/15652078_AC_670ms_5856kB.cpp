#include <iostream>
#include<stdio.h>
using namespace std;
const int N=1e6+50;
struct node{
    int left,right;
    int weight;
    int flag;
}tree[4*N];
void build(int k,int ll,int rr,int x)     //非输入建树，初始化为x
{
    tree[k].left=ll;
    tree[k].right=rr;
    tree[k].flag=0;                                                         //*******
    if(tree[k].left==tree[k].right)
    {
        tree[k].weight=x;             //***
        return ;
    }
    int mid=(ll+rr)/2;
    build(2*k,ll,mid,x);              //***
    build(2*k+1,mid+1,rr,x);        //***
    tree[k].weight=tree[2*k].weight+tree[2*k+1].weight;
}
void down(int k)
{
    tree[2*k].flag=tree[k].flag;
    tree[2*k+1].flag=tree[k].flag;
    tree[2*k].weight=tree[k].flag*(tree[2*k].right-tree[2*k].left+1);
    tree[2*k+1].weight=tree[k].flag*(tree[2*k+1].right-tree[2*k+1].left+1);
    tree[k].flag=0;
}
void change_interval(int k,int a,int b,int y)       //改为y
{
    if(tree[k].left>=a&&tree[k].right<=b)
    {
        tree[k].weight=(tree[k].right-tree[k].left+1)*y;
        tree[k].flag=y;
        return ;
    }
    if(tree[k].flag)
        down(k);
    int mid=(tree[k].left+tree[k].right)/2;
    if(a<=mid)
       change_interval(2*k,a,b,y);
    if(b>mid)
        change_interval(2*k+1,a,b,y);
    tree[k].weight=tree[2*k].weight+tree[2*k+1].weight;
}
int main()
{
   int t,n,q;
   scanf("%d",&t);
   for(int i=1;i<=t;i++)
   {
    scanf("%d%d",&n,&q);
    build(1,1,n,1);
    int u,v,w;
    while(q--)
    {
        scanf("%d%d%d",&u,&v,&w);
        change_interval(1,u,v,w);
    }
    printf("Case %d: The total value of the hook is %d.\n",i,tree[1].weight);
   }
    return 0;
}