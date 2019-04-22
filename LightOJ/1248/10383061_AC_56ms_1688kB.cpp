#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
    int Case,n;
    
    cin >> Case;
    int temp = Case;
    while(Case--)
    {
        cin>>n;
        double ans = 0;
        for(int i=1;i<=n;i++)
            ans += (double)n/(double)i;
        printf("Case %d: %.10f\n", temp-Case, ans);

    }
}