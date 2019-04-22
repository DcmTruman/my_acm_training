#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
long long MOD = 1e9+7;

int main()
{
    int N;
    cin>>N;
    while(N--)
    {
    long long n,B;
    cin>>n>>B;
    for(long long i=0;i<9973;i++)
    {
        long long x = B*i-n;
        if(x%9973 == 0)
        {
            cout<<i<<endl;
        }
    }
    }
}