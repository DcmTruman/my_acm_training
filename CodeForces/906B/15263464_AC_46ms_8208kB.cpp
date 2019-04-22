#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
typedef long long ll;
int p[maxn],n,m;;
const int vx[]={-1,0,0,1},vy[]={0,-1,1,0};
bool check(int i,int j)
{
    int x1=i/m,y1=i%m;
    int x2=j/m,y2=j%m;
    for(int u=0;u<4;u++) if(x1+vx[u]==x2&&y1+vy[u]==y2) return true;
    return false;
}
bool dfs(int i)
{
    if(i==n*m) return true;
    int x=i/m,y=i%m;
    for(int j=i;j<n*m;j++){
        swap(p[i],p[j]);
         if(x&&check(p[i],p[(x-1)*m+y])) continue;
         if(y&&check(p[i],p[x*m+y-1])) continue;
         if(dfs(i+1)) return true;
         swap(p[i],p[j]);
    }
    return false;
}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n*m;i++) p[i]=i;
        if(dfs(0))
        {
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(j==m-1)
                     printf("%d\n",p[i*m+j]+1);
                     else printf("%d ",p[i*m+j]+1);
                }
            }
        }else cout<<"NO"<<endl;
    }
}