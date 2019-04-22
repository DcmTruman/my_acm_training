#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
long long MOD = 1e9+7;
typedef long long ll ;
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
const ll maxn = 100020;
ll sum[maxn];
int n;
int main()
{
    string s;
    int a,b;
    while(cin>>n)
    {
        cin>>s;
        
        sum[0] = 1;
        for(int i=1;i<=s.size();i++)
        {
            sum[i] = sum[i-1]*(s[i-1]-28)%9973;
        }
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            ll temp = ex_inv(sum[a-1], 9973);
            cout<<(sum[b]*temp)%9973<<endl;
        }
    }
}