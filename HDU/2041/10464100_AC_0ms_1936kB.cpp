#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
int n,dp[42],a;
int main()
{
    cin>>n;
    dp[2] = 1;
    dp[3] = 2;
    for(int i =4;i<=40;i++)
    {
        dp[i] = dp[i-2]+dp[i-1];
    }
    while(n--)
    {
        cin>>a;
        cout<<dp[a]<<endl;
    }
}
