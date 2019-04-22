#include<iostream>
#include<stdio.h>
using namespace std;

typedef long long LL;
const int maxn = 1e6+20;
const int MOD = 1e9+7;
LL Inv[maxn];
LL Cm[maxn],Ck[maxn];
LL m,n,k;
LL Quickpow(LL a,LL b){
    LL r=1,base=a;
    while(b){
        if(b&1) r = r*base%MOD;
        base = base*base%MOD;
        b>>=1;
    }
    return r;
}

void ex_gcd(LL a,LL b,LL &x,LL&y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    LL c,d;
    ex_gcd(b, a%b, c, d);
    x = d;
    y = c - (a/b)*d;
}
void initInv()
{
    Inv[1] = 1;
    for(int i =2;i<maxn;i++)
    {
        LL temp;
        ex_gcd(i, MOD, Inv[i], temp);
        Inv[i] = (Inv[i]%MOD+MOD)%MOD;
    }
}
void initC()
{
    Cm[0] = 1;
    Ck[0] = 1;
    for(int i =1;i<=k;i++)
    {
        Cm[i] = (Cm[i-1]%MOD * (m-i+1)%MOD * Inv[i]%MOD)%MOD;
        Ck[i] = (Ck[i-1]%MOD * (k-i+1)%MOD * Inv[i]%MOD)%MOD;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    long long Case;
    cin>>Case;
    long long t = Case;
    LL ans;
    initInv();
    while(Case--)
    {
        cin>>n>>m>>k;
        initC();
        LL temp = 1;
        ans = 0;
        for(LL i = k;i>=1;i--)
        {
            ans = (ans+temp*i*Ck[i]%MOD*Quickpow(i-1,n-1)%MOD+MOD)%MOD;
            temp = -temp;
        }
        ans = ans*Cm[k]%MOD;
        cout<<"Case #"<<t-Case<<": "<<ans<<endl;
    }
}