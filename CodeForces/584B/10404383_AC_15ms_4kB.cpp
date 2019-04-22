#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
long long MOD = 1e9+7;

long long POW(long long a,long long b){
    long long r=1,base=a;
    while(b){
        if(b&1) r = r*base%MOD;
        base = base*base%MOD;
        b>>=1;
    }
    return r;
}
int main()
{
    int n;
    cin>>n;
    cout<<(POW(27,n)+MOD-POW(7,n))%MOD<<endl;
}