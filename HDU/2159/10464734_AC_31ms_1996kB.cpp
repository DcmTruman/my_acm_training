#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,k,s;
int ex[120],st[120],dp[120][120];
int main()
{
    while(cin>>n>>m>>k>>s)
    {
        for(int i = 1;i<=k;i++)
        {
            cin>>ex[i]>>st[i];
        }
        for(int i = 0;i<120;i++)
        {
            for(int j =0;j<120;j++)
            {
                dp[i][j] = 0;
            }
        }
        for(int i = 1;i<=k;i++)
        {
            for(int j = st[i];j<=m;j++)
            {
                for(int p = 1;p<=s;p++)
                {
                    if(dp[j][p]<dp[j-st[i]][p-1]+ex[i])
                    {
                        dp[j][p] = dp[j-st[i]][p-1]+ex[i];
                    }
                }
            }
        }
        if(dp[m][s]>=n)
        {
            for(int i =0;i<=m;i++)
            {
                if(dp[i][s] >= n)
                {
                    cout<<m-i<<endl;
                    break;
                }
            }
        }
        else{
            cout<<"-1"<<endl;
        }
    }
}
