#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 200010
#define lson l,m,root<<1
#define rson m+1,r,root<<1|1
int node[maxn<<2];
void pushup(int root)
{
    node[root]=max(node[root<<1],node[root<<1|1]);
}
void build(int l,int r,int root)
{
    if(l==r)
    {
        scanf("%d",&node[root]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(root);
}
void update(int a,int b,int l,int r,int root)
{
    if(l==r)
    {
        node[root]=b;
        return;
    }
    int m=(l+r)>>1;
    if(a<=m)
    {
        update(a,b,lson);
    }
    else
    {
        update(a,b,rson);
    }
    pushup(root);
}
int Queue(int a,int b,int l,int r,int root)
{
    if(a<=l&&b>=r)
    {
        return node[root];
    }
    int m=(l+r)>>1;
    int ret=0;
    if(a<=m)
    {
       ret=max(ret,Queue(a,b,lson));//这个地方一开始多写了个return结果一直WA TAT如果加了return就不会执行下面的代码了
    }
    if(b>m)
    {
    ret=max(ret,Queue(a,b,rson));
    }
    return ret;
}
int main()
{
   int n,m;
   while(~scanf("%d %d",&n,&m))
   {
       build(1,n,1);
       while(m--)
       {
           char op[2];
           int a,b;
           scanf("%s%d%d",op,&a,&b);
           if(op[0]=='Q')
           {
               int num=Queue(a,b,1,n,1);
               printf("%d\n",num);
           }
           else
           {
               update(a,b,1,n,1);
           }
       }
   }
   return 0;
}