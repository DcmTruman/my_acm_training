#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
using namespace std;
int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a%b);
}
int main()
{
    int Case,n,sum,d;
    cin>>Case;
    int temp = Case;
    while(Case--)
    {
        getchar();
        cin>>n;
        d = 0;
        sum = 0;
        int a;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a<0)
            {
                d++;
                sum += -a;
            }
            else
            {
                sum += a;
            }
        }
        if(n!=d)
        {
        printf("Case %d: %d/%d\n",temp-Case,sum/GCD(sum,n-d),(n-d)/GCD(sum,n-d));
        }
        else
        {
           printf("Case %d: inf\n",temp-Case);
        }
    }
}