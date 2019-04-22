#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
using namespace std;
const int MAX = 1e5+20;
double dp[MAX];
void DP()
{
    dp[1] = 0;
    for(int i = 2;i<MAX;i++)
    {
        double temp = 0;
        int num = 0;
        for(int j =1;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                temp += dp[i/j];
                num ++;
                if(j*j!=i){
                    temp += dp[j];
                    num ++;
                }
            }
        }
        temp += num;
        dp[i] = temp/(num-1);
    }
}
int main()
{
    int Case,n;
    cin >> Case;
    int temp = Case;
    DP();
    while(Case--)
    {
        cin>>n;
        printf("Case %d: %lf\n",temp-Case,dp[n]);
    }
}