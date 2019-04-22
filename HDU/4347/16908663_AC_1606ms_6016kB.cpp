#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

#define maxn 100010
struct node
{
    ll pos[10];
    int id;
}tree[maxn],op,point;

int split[maxn],N,now,demension;
bool vis[maxn];
ll ans,id;
double var[10];
bool cmp(const node &a,const node &b)
{
    return a.pos[split[now]] < b.pos[split[now]];
}

void build(int L , int R)
{
    if(L > R)return;
    int mid = (L + R)/2;
    //求出每一维度的方差
    for(int pos = 0;pos < demension ; pos ++)
    {
        double avg = var[pos] = 0;
        for(int i = L;i <= R ;i++)
        {
            avg += tree[i].pos[pos];
        }
        avg /= (R - L + 1);
        for(int i = L;i<= R;i++)
        {
            var[pos] += (tree[i].pos[pos] - avg) * (tree[i].pos[pos] - avg);
        }
        var[pos] /= (R - L + 1);
    }
    split[now = mid] = 0;
    for(int i = 1;i < demension;i++)
    {
        if(var[split[mid]] < var[i]) split[mid] = i;
    }
    nth_element(tree+L,tree+mid,tree+R+1,cmp);
    build(L,mid - 1);
    build(mid + 1 , R);
}

void query(int L , int R)
{
    if(L > R)return;
    int mid = (L + R)/2;
    ll dis = 0;
    //求目标点到根节点的距离
    for(int i = 0;i<demension;i++){
        dis += (op.pos[i] - tree[mid].pos[i]) * (op.pos[i] - tree[mid].pos[i]);
    }
    if(!vis[tree[mid].id] && dis < ans)
    {
        ans = dis;
        id = tree[mid].id;
        point = tree[mid];
    }
    //计算op到分裂平面的距离
    ll ra = (op.pos[split[mid]] - tree[mid].pos[split[mid]]) *(op.pos[split[mid]] - tree[mid].pos[split[mid]]);

    if (op.pos[split[mid]] < tree[mid].pos[split[mid]])
    {
        query(L,mid - 1);
        if (ra <= ans) query(mid + 1,R);
    }
    else 
    {
        query(mid+1,R);
        if(ra <= ans)query(L,mid - 1);
    }
}

node ret[20];
int main()
{
    while(scanf("%d%d",&N,&demension)!=EOF)
    {
        for(int i = 1;i<= N;i++)
        {
            for(int j = 0;j<demension;j++)
            {
                scanf("%lld",&tree[i].pos[j]);
            }
        }
        for(int i = 1;i <= N;i++)tree[i].id = i;
        build(1,N);
        int T;
        scanf("%d",&T);
        for(int i = 1;i<=T;i++)
        {
            for(int j = 0;j<demension;j++)
            {
                scanf("%lld",&op.pos[j]);
            }
            memset(vis,0,sizeof(vis));
            int m;
            scanf("%d",&m);
            for(int j = 0;j < m;j++)
            {
                ans = INF;
                query(1,N);
                ret[j] = point;
                vis[id] = true;
            }
            printf("the closest %d points are:\n",m);
            for(int j = 0;j < m;j++)
            {
                printf("%lld",ret[j].pos[0]);
                for(int k = 1;k<demension;k++){
                    printf(" %lld",ret[j].pos[k]);
                }
                putchar('\n');
            }
        }
    }
}