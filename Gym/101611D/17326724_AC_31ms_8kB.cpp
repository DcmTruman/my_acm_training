#include <iostream>
#include <stdio.h>
#include <algorithm>
#define ll unsigned long long 

using namespace std;

ll msb(ll n)
{
    return ((n) & (1ll<<7));
}

ll pow4(ll a,ll b){
  ll r=1ll,base=a;
  while(b){
    if(b&1ll) r*=base;
    base*=base;
    b>>=1;
  }
  return r;
}



int main()
{
    int n;
    //while(~scanf("%d",&n);
    scanf("%d",&n);
    ll ans = 0;
    ll cnt = 0;
    while(n--)
    {
        ll  a;
        scanf("%llu",&a);
        //cout << a<<endl;
        if(a < 128){
            ans += a*pow4(2,7*(cnt));
            cnt = 0;
            //ans = 0;
            if(ans%2 == 0){
                printf("%llu\n",ans/2);
            }
            else{
                printf("-%llu\n",ans/2+1);
            }
            ans = 0;
        }        
        else{
            //cout << ans << endl;
            ans += (a-128)*pow4(2,7*(cnt));
            cnt ++;
        }
    } 
}