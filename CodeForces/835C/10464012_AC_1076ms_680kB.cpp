#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
int dp[120][120][12];
int n,x,y,s,q,c;
int t,x1,y_1,x2,y2;
int main()
{
    cin>>n>>q>>c;
    for(int i = 0;i<n;i++)
    {
        cin>>x>>y>>s;
        dp[x][y][s]++;
    }
    for(int  i =1;i<=100;i++)
    {
        for(int  j = 1;j<=100;j++)
        {
            for(int k = 0;k<=c;k++)
            {
                dp[i][j][k] = dp[i][j][k] + dp[i-1][j][k] + dp[i][j-1][k]-dp[i-1][j-1][k];
            }
        }
    }
    for(int i = 0;i<q;i++)
    {
        cin>>t>>x1>>y_1>>x2>>y2;
        int ans = 0;
        for(int i = 0;i<=c;i++)
        {
            int l = (t+i)%(c+1);
            ans += l*(dp[x2][y2][i]-dp[x2][y_1-1][i]-dp[x1-1][y2][i]+dp[x1-1][y_1-1][i]);
        }
        cout<<ans<<endl;
    }
    
}
