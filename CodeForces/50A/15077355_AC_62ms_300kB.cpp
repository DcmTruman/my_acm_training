#include <iostream>

using namespace std;
int main()
{
int n,m,ans;
while(cin>>n>>m)
{
ans=n*(m/2)+m%2*(n/2);
cout<<ans<<endl;
}
}