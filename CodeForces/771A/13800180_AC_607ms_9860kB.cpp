#include<iostream>
using namespace std;

int fa[150020];
typedef long long LL;
void init(int n)
{
    for(int i = 1;i<=n;i++)
    {
        fa[i] = i;
    }
}

int find(int x)
{
    return (x!=fa[x])?fa[x] = find(fa[x]):fa[x];
}

void join(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx!=fy)
    {
        fa[fx] = fy;
    } 
}
LL t[150020];
int main()
{
    LL sum = 0;
    int n,m;
    int x,y;
    cin>>n>>m;
    init(n);
    for(int i = 0;i<m;i++)
    {
        cin>>x>>y;
        join(x,y);
    }
    for(int i = 1;i<=n;i++)
    {
        t[find(i)]++;
    }
    for(int i = 1;i<=n;i++)
    {
        if(t[i]!=0&&t[i]!=1)
        {
            sum += (t[i]*(t[i]-1))/2;
        }
    }
    if(sum != m)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}