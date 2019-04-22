#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll n,ll m)
{
    if (m==0) return n;
    return gcd(m,n%m);
}
int main()
{
    ios::sync_with_stdio(false);
    int T,ans,kase=1;
    ll x,n,m;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        if (n>m) swap(n,m);
        ans=1;
        //cout<<"Debug  :"<<n<<" "<<m<<endl;
        while (true) {
            x=1+n/gcd(n,m);
            if (m%x!=0) break;
            if (gcd(m/x,n)!=gcd(m,n)) break;
            ans++;
            m=m/x;
            if (n>m) swap(n,m);
            //cout<<"Debug  :"<<n<<" "<<m<<endl;
        }
        cout<<"Case #"<<kase++<<": "; cout<<ans<<endl;
    }
    return 0;
}