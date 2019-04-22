#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
using namespace std;
long long dp[50];
void DP()
{
    int i, j;
    dp[0] = 1;
    for(i = 1; i < 40; i++)
    {
        dp[i] = 0;
        for(j = 0; j <= i; j++)
        {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
}
int main()
{
    int n;
    DP();
    cin>>n;
    int temp = 1;
    while(n!=-1)
    {
        printf("%d %d %lld\n", temp++, n, dp[n]*2);
        cin>>n;
    }
}