#include <iostream>
#include <stdio.h>
#define ll unsigned long long 
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    ll cnt = 0;
    ll ans = 0;
    while(n--)
    {
        int a;
        scanf("%d",&a);
        if(a < 128){
            ans += a*(1ll << (7*cnt));
            if(ans % 2 == 1)printf("-%llu\n",ans/2+1);
            else printf("%llu\n",ans/2);
            ans = 0;
            cnt = 0;
        }else{
            ans += (a-128)*(1ll << (7*cnt));
            cnt ++;
        }
    }
}