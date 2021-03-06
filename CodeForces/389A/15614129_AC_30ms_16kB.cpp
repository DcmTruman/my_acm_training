#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

typedef long long ll;

ll mod;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(a==0&&b==0)return -1;
	if(b==0){
		x = 1;y = 0;
		return a;
	}
	ll ans = exgcd(b,a%b,y,x);
	y -= a/b*x;
	return ans;
}

ll gcd(ll a,ll b){
	return (b!=0)?gcd(b,a%b):a;
} 

ll line(ll a,ll b,ll c,ll &x,ll &y){
	ll d = exgcd(a,b,x,y);
	if(c%d == 0){
		ll k = c/d;x*=k;//y*=k;
        y=b/d;
		return true;
	}
	return false;
}
int main()
{
    int n;cin>>n;
    ll a[120];
    for(int i = 0;i<n;i++)cin>>a[i];
    ll ans = a[0];
    for(int i = 1;i<n;i++)ans = gcd(ans,a[i]);
    cout<<ans*n<<endl; 
    return 0;
}