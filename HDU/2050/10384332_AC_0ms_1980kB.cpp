#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
using namespace std;
int dp[10020];
void DP()
{
    dp[1] = 2;
    for(int i =2;i<10010;i++)
    {
        dp[i] = dp[i-1] +4*i-3;
    }
}
int main()
{
    int Case,n;
    DP();
    cin>>Case;
    while(Case--)
    {
        cin>>n;
        cout<<dp[n]<<endl;
    }
}