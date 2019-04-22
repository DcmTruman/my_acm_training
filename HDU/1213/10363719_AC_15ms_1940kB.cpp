#include<iostream>
#include<vector>
using namespace std;
int Case,n,k,ans;
int f[1020];
int find(int x)
{
    if(x!=f[x])f[x] = find(f[x]);
    return f[x];
}
void Union(int a,int b)
{
    int x = find(a);
    int y = find(b);
    if(x == y)return;
    ans -= 1;
    f[y] = x;
}
int main()
{
    cin>>Case;
    while(Case--)
    {
        cin>>n>>k;
        ans = n;
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=1;i<=k;i++)
        {
            int x,y;
            cin>>x>>y;
            Union(x,y);
        }
        cout<<ans<<endl;
        getchar();
    }
}