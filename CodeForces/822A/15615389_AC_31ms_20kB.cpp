#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<stdio.h>
#define clr(x,b) memset(x,(b),sizeof(x));
using namespace std;

typedef long long ll;

const int maxn = 1e5+7;



int main()
{
    int a,b;cin>>a>>b;
    int c = min(a,b);
    ll ans = 1;
    for(int i = 1;i<=c;i++)ans*=i;
    cout<<ans<<endl;
}