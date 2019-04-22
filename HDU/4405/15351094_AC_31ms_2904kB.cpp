#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cstring>
#define ll long long
double dp[100005];
int vis[100005];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if((n+m)==0)break;
        memset(vis,-1,sizeof(vis));
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            vis[a]=b;
        }
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            if(vis[i]==-1){
                for(int j=1;j<=6;j++){
                    dp[i]+=dp[i+j]/6.0;
                }
                dp[i]+=1;
            }
            else
                 dp[i]=dp[vis[i]];
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}