#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int father[100005];
unsigned long long mod=1e9+7;
unsigned long long k1,k2;
unsigned long long ran()
{
    unsigned long long k3=k1,k4=k2;
    k1=k4;
    k3^=k3<<23;
    k2=k3^k4^(k3>>17)^(k4>>26);
    return k2+k4;
}
struct node
{
    int u,v;
    unsigned long long w;
}edge[100001];
int n,m;
void gen()
{
    scanf("%d%d%llu%llu",&n,&m,&k1,&k2);
    for(int i=1;i<=m;i++)
    {
        edge[i].u=ran()%n+1;
        edge[i].v=ran()%n+1;
        edge[i].w=ran();
    }
}
int cmp(node a,node b)
{
    return a.w<b.w;
}
int fi(int x)
{
    if(father[x]==x) return x;
    return father[x]=fi(father[x]);
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        gen();
        unsigned long long ans=0;
        int cnt=0;
        sort(edge+1,edge+1+m,cmp);
        for(int i=1;i<=m;i++)father[i]=i;
        for(int i=1;i<=m;i++)
        {
            if(fi(edge[i].u)!=fi(edge[i].v))
            {
                father[fi(edge[i].u)]=fi(edge[i].v);
                ans=(ans+edge[i].w)%mod;
                cnt++;
            }
        }
        if(cnt!=n-1) printf("0\n");
        else printf("%llu\n",ans);

    }

}
