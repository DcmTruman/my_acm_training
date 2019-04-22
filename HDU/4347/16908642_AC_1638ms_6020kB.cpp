#include <map>
//KD树学习http://blog.csdn.net/zhjchengfeng5/article/details/7855241
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <stack>
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define PI 3.1415926535897932626
using namespace std;
int gcd(int a, int b) {return a % b == 0 ? b : gcd(b, a % b);}
#define MAXN 100010
const LL INF = LONG_LONG_MAX;
struct node
{
    LL pos[10];
    int id;
}tree[MAXN],op,point;
int split[MAXN],N,now,demension;
bool used[MAXN];
LL ans,id;
double var[10];
bool cmp(const node &a,const node &b)
{
    return a.pos[split[now]] < b.pos[split[now]];
}
void build(int L,int R)
{
    if (L > R) return;
    int mid = (L + R) / 2;
    //求出每一唯上的方差
    for (int pos = 0 ; pos < demension ; pos++)
    {
        double avg = var[pos] = 0;
        for (int i = L ; i <= R; i++)
            avg += tree[i].pos[pos];
        avg /= (R - L + 1);
        for (int i = L ; i <= R; i++)
            var[pos] += (tree[i].pos[pos] - avg) * (tree[i].pos[pos] - avg);
        var[pos] /= (R - L + 1);
    }
    //找到方差最大的那一个唯独
    split[now = mid] = 0;
    for (int i = 1; i < demension ; i++)
        if (var[split[mid]] < var[i]) split[mid] = i;
    nth_element(tree + L ,tree + mid,tree + R + 1,cmp);
    build(L,mid - 1);
    build(mid + 1,R);
}
void query(int L,int R)
{
    if (L > R) return;
    int mid = (L + R) / 2;
    LL dis = 0;
    //求出目标点到当前根节点的距
    for (int i = 0 ; i < demension ; i++)
        dis += (op.pos[i] - tree[mid].pos[i]) * (op.pos[i] - tree[mid].pos[i]);
    //if (dis == 0) dis = INF;
    //printf("%lld\n",dis);
    //如果当前节点能够用来更新最近距离并且dis<ans
    if (!used[tree[mid].id] && dis < ans)
    {
        ans = dis;
        id = tree[mid].id;
        point = tree[mid];
    }
    //计算op到分裂平面的距离
    LL radius = (op.pos[split[mid]] - tree[mid].pos[split[mid]]) *
    (op.pos[split[mid]] - tree[mid].pos[split[mid]]);
    //对子区间进行查询
    if (op.pos[split[mid]] < tree[mid].pos[split[mid]])
    {
        query(L,mid - 1);
        if (radius <= ans) query(mid + 1,R);
    }
    else
    {
        query(mid + 1,R);
        if (radius <= ans) query(L,mid - 1);
    }
}
node ret[20];
int main()
{
   // freopen("sample.txt","r",stdin);
    while (scanf("%d%d",&N,&demension) != EOF)
    {
        for (int i = 1; i <= N; i++)
            for (int j = 0 ;j < demension ; j++)
            scanf("%lld",&tree[i].pos[j]);
        for (int i = 1; i <= N; i++) tree[i].id = i;
        build(1,N);
        int T;
        scanf("%d",&T);
        for (int i = 1; i <= T; i++)
        {
            for (int j = 0;  j < demension ; j++)
                scanf("%lld",&op.pos[j]);
            //printf("%lld %lld\n",op.pos[0],op.pos[1]);
            memset(used,false,sizeof(used));
            int m;
            scanf("%d",&m);
            for (int j = 0 ; j < m ; j++)
            {
                ans = INF;
                query(1,N);
                ret[j] = point;
                //printf("%lld\n",id);
                used[id] = true;
            }
            printf("the closest %d points are:\n",m);
            for (int j = 0 ; j < m ; j++)
            {
                printf("%lld",ret[j].pos[0]);
                for (int k = 1; k < demension ; k++)
                    printf(" %lld",ret[j].pos[k]);
                putchar('\n');
            }
        }
    }
}