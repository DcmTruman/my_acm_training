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
    ll a,b;
    ll A,B,C,k;
    while(cin>>A>>B>>C>>k){
        //A+Cx=B(%mod)
        //Cx=B-A
        //Cx+ny=B-A(%mod)
        if(A==0&&B==0&&C==0&&k==0)break;
        mod = (ll)1<<k;
        ll a = C;
        ll b = mod;
        ll d = B-A;
        ll x,y;
        
        if(line(a,b,d,x,y)){
            x = (x%y+y)%y;
            cout<<x<<endl;
        }
        else cout<<"FOREVER\n";
        
    }
}