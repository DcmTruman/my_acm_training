#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

typedef long long ll;


int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    a /=1;b/=2;c/=4;
    cout<<min(min(a,b),c)*7<<endl;
}