#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll ;
ll MOD = 1e9+7;

ll ex_gcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0){
        x = 1;y = 0;
        return a;
    }
    ll ans = ex_gcd(b,a%b,y,x);
    y -= a/b*x;
    return ans;
}
ll ex_inv(ll a,ll b)
{
    ll x,y;
    ll d = ex_gcd(a, b, x, y);
    return (x%b+b)%b;
}

ll POW(ll a,ll b){
    ll r=1,base=a;
    while(b){
        if(b&1) r = r*base%MOD;
        base = base*base%MOD;
        b>>=1;
    }
    return r;
}

int n;
int main()
{
    string s;
    ll k;
    cin>>s>>k;
    int len = s.length();
    ll temp = 0;
    for(int i=0;i<len;i++)
    {
        if(s[i] == '0'||s[i] == '5')
        {
            temp = (temp + POW(2,i))%MOD;
        }
    }
    ll t = POW(2,len);
    ll a = (1-POW(t,k)+MOD)%MOD;
    ll b = (1-t+MOD)%MOD;
    ll ans = temp*((a*POW(b,MOD-2))%MOD)%MOD;
    cout<<ans<<endl;
}