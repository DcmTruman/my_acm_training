#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define lson l,m,rt*2
#define rson m+1,r,rt*2+1
int tree[1000050*8];
char a[405000];
int sum[405000];
void pushup(int rt)
{
    tree[rt]=min(tree[rt<<1],tree[rt<<1|1]);
}
int Query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        return tree[rt];
    }
    else
    {
        int m=(l+r)>>1;
        int ans=0x3f3f3f3f;
        if(L<=m)
        {
            ans=min(Query(L,R,lson),ans);
        }
        if(m<R)
        {
            ans=min(Query(L,R,rson),ans);
        }
        return ans;
    }
}
void build( int l ,int r , int rt )
{
    if( l == r )
    {
        tree[rt]=0x3f3f3f3f;
        return ;
    }
    else
    {
        int m = (l+r)>>1 ;
        build(lson) ;
        build(rson) ;
        pushup(rt) ;
    }
}
void update(int p,int c,int l,int r,int rt)//p阵营c数据.
{
    if(l==r)
    {
        tree[rt]=min(tree[rt],c);
    }
    else
    {
        int m=(l+r)>>1;
        if(p<=m) update(p,c,lson);
        else  update(p,c,rson);
        pushup(rt);
    }
}
int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q))
    {
        scanf("%s",a);
        sum[0]=1;
        build(1,n,1);
        for(int i=1;i<n;i++)
        {
            int tmp=0;
            if(a[i]=='(')tmp=1;
            else tmp=-1;
            sum[i]=sum[i-1]+tmp;
        }
        for(int i=1;i<=n;i++)update(i,sum[i-1],1,n,1);
        while(q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x>y)swap(x,y);
            if(a[x-1]==a[y-1])printf("Yes\n");
            if(a[x-1]==')'&&a[y-1]=='(')printf("Yes\n");
            if(a[x-1]=='('&&a[y-1]==')')
            {
                if(Query(x,y-1,1,n,1)<2)printf("No\n");
                else printf("Yes\n");
            }
        }
    }
}