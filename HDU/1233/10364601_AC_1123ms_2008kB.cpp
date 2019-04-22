#include<iostream>
#include <algorithm>
using namespace std;
int n,ans;
int f[120];
typedef struct _fff
{
    int from,to,dis;
}FFF;
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
}
int main()
{
    cin>>n;
    while(n)
    {
        ans = 0;
        for(int i=1;i<=n;i++)f[i] = i;
        int k =n*(n-1)/2;
        for(int i=0;i<k;i++)
        {
            cin>>edge[i].from>>edge[i].to>>edge[i].dis;
        }
        sort(edge,edge+k,cmp);
        for(int i = 0;i<k;i++)
        {
            Union(edge[i].from,edge[i].to,i);
        }
        cout<<ans<<endl;
        cin>>n;
    }
}