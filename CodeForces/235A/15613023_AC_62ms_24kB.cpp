#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

typedef long long ll;


int main()
{
    ll n;
    ll ans;
    while(cin>>n){
        if(n<=2)ans=n;
        else if(n&1)ans=n*(n-1)*(n-2);
        else{
            if(n%3!=0)ans=n*(n-1)*(n-3);
            else ans=(n-1)*(n-2)*(n-3);
        }
        cout<<ans<<endl;
    }
}