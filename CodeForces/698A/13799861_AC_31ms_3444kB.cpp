#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>


using namespace std;
const int INF = 0x3f3f3f3f;
int dp[120][4];
int days[120];
int main()
{
    int N;
    int m;
    memset(dp,INF,sizeof(dp));
    cin>>N;
    dp[0][0] = 0;
    for(int i = 1;i<=N;i++)
    {
        cin>>m;
        dp[i][0] = min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
        if(m == 1)
        {
            dp[i][1] = min(dp[i-1][2],dp[i-1][0]);
        }
        else if(m == 2)
        {
            dp[i][2] = min(dp[i-1][1],dp[i-1][0]);
        }
        else if(m == 3)
        {
            dp[i][1] = min(dp[i-1][2],dp[i-1][0]);
            dp[i][2] = min(dp[i-1][1],dp[i-1][0]);
        }
    }
    cout<<min(min(dp[N][0],dp[N][1]),dp[N][2])<<endl;
}