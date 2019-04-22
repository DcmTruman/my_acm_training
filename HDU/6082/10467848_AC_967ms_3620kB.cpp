#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int INF=0x3f3f3f3f;
long long a[100020],b[100020],k[2020],p[2020];
long long dp[1020][12];
long long m,n;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        long long hpx = 0,atx = 0,fyx = 0;
        for(int i =0;i < n;i++)
        {
            cin>>a[i];
            hpx = max(hpx,a[i]);
            cin>>b[i];
            fyx = max(fyx,b[i]);
        }
        for(int i = 0;i<m;i++)
        {
            cin>>k[i];
            cin>>p[i];
            atx = max(atx,p[i]);
        }
        if(atx<=fyx)
        {
            cout<<"-1"<<endl;
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(int i =0;i<=10;i++)
        {
            for(int j = 1;j<=hpx;j++)
            {
                dp[j][i] = INF;
                for(int t = 0;t<m;t++)
                {
                    long long s = p[t] - i;
                    if(s <= 0)continue;
                    else if(j<=s)
                    {
                        dp[j][i] = min(dp[j][i],k[t]);
                    }
                    else
                    {
                        dp[j][i] = min(dp[j][i],dp[j-s][i]+k[t]);
                    }
                }
            }
            
        }
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += dp[a[i]][b[i]];
        }
        cout<<ans<<endl;
    }
}
