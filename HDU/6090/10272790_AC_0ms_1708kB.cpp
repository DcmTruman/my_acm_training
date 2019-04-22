#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    long long N,n,m;
    cin>>N;
    while(N--)
    {
        cin>>n>>m;
        if(m>=n*(n-1)/2)cout<<n*(n-1)<<endl;
        else if( m < n-1)cout<<2*m*m+(m+n)*(n-m-1)*n<<endl;
        else cout<<2*(n-1)*(n-1)-2*(m-n+1)<<endl;
    }
}