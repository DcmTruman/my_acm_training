#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    int T,n,k;
    cin>>T;
    int t = T;
    while(T--)
    {
        cin>>n>>k;
        if(k>=n)printf("Case %d: first\n",t-T);
        else
        {
            if(k == 1)
            {
                if(n&1)printf("Case %d: first\n",t-T);
                else printf("Case %d: second\n",t-T);
            }
            else if(k >= 2)
            {
                printf("Case %d: second\n",t-T);
            }
        }
    }
}