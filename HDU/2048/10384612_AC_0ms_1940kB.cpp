#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
using namespace std;
double dp[30];
void DP()
{
    dp[1] = 0;
    dp[2] = 1;
    for(int i =3;i<21;i++)
    {
        dp[i] =(i-1)*(dp[i-1]+dp[i-2]);
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
        long long temp = 1;
        for(int j=2;j<=n;j++)
            temp *=j;
        double ans = dp[n]*100.0/temp;
        printf("%.2f%%\n",ans);
    }
}