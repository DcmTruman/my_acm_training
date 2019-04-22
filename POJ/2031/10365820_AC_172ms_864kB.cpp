#include<iostream>
#include <algorithm>
#include<math.h>
#include<stdio.h>
using namespace std;
int n,num,k;
double ans;
int f[5020];
typedef struct _fff
{
    int from,to;
    double dis;
}FFF;
typedef struct _ff{
    double x,y,z,r;
}node;
node Node[120];
FFF edge[5020];
bool cmp(FFF a,FFF b)
{
    return a.dis < b.dis;
}
int find(int x)
{
    if(x!=f[x])f[x] = find(f[x]);
    return f[x];
}
void Union(int a,int b,int i)
{
    int x = find(a);
    int y = find(b);
    if(x == y)return;
    ans += edge[i].dis;
    f[y] = x;
    num++;
}
int main()
{
    cin>>n;
    while(n)
    {
        ans = 0,num = 1;

        for(int i=0;i<n;i++)
        {
            cin>>Node[i].x>>Node[i].y>>Node[i].z>>Node[i].r;
        }
        k = 0;
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                edge[k].from = i;
                edge[k].to = j;
                
                edge[k].dis = sqrt((Node[i].x-Node[j].x)*(Node[i].x-Node[j].x)+(Node[i].y-Node[j].y)*(Node[i].y-Node[j].y)+(Node[i].z-Node[j].z)*(Node[i].z-Node[j].z))-(Node[i].r+Node[j].r);
                if(edge[k].dis<0)edge[k].dis = 0;
                k++;
            }
        }
        for(int i=0;i<=n;i++)f[i] = i;
        sort(edge,edge+k,cmp);
        for(int i = 0;i<k;i++)
        {
            int x = find(edge[i].from);
            int y = find(edge[i].to);
            if(x != y)
            {
                ans += edge[i].dis;
                f[x] = y;
                num ++;
                if(num == n)break;
            }
            
        }
        printf("%.3f\n",ans);
        cin>>n;
    }
}