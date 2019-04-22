#include<iostream>
#include<string.h>
#include<stdio.h>
#include<set>
#include<math.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    if(n>m)cout<<n - 1<<" "<<m;
    else cout<<m - 1<<" "<<n;
}