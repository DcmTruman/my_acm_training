#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn=100000+10;
const int inf=0x3f3f3f3f;
struct node
{
    int v,w,next;
}E[maxn];
int d[maxn],first[maxn],inq[maxn],a[maxn],b[maxn];
int n,m,len,st_num,ed_num;

void spfa()
{
    memset(inq,0,sizeof(inq));
    memset(d,inf,sizeof(d));
    queue<int>q;
    int st=0;
    d[st]=0,inq[st]=1;
    q.push(st);
    while(!q.empty())
    {
        st=q.front();
        q.pop();
        inq[st]=0;
        for(int i=first[st];~i;i=E[i].next)
        {
            int v=E[i].v,w=E[i].w;
            if(d[v]>d[st]+w)
            {
                d[v]=d[st]+w;
                if(!inq[v])
                {
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
    int ans=inf;
    for(int i=0;i<ed_num;++i)
        if(d[b[i]]<ans)
            ans=d[b[i]];
    printf("%d\n",ans);
}

void add_edge(int u,int v,int w)
{
    E[len].v=v,E[len].w=w;
    E[len].next=first[u];
    first[u]=len++;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        len=0;
        memset(first,-1,sizeof(first));
        int u,v,w;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
        }
        scanf("%d",&st_num);
        for(int i=0;i<st_num;++i)
        {
            scanf("%d",&a[i]);
            add_edge(0,a[i],0);
        }
        scanf("%d",&ed_num);
        for(int i=0;i<ed_num;++i)
            scanf("%d",&b[i]);
        spfa();
    }
    return 0;
}