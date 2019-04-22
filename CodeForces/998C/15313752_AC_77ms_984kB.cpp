#include<iostream>
#include<string.h>
#include<algorithm>

#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
using namespace std;

const int maxn = 120;




int main()
{
	ll n,x,y;cin>>n>>x>>y;
	ll ans = 0;
	string s;
	cin>>s;
	ll cnt = 0;
	for(int i = 0;i<n-1;i++)
	{
		if(s[i] == '0'&&s[i+1] == '1')cnt++;
	}
	
	if(s[n-1] == '0')cnt++;
	if(x<y)ans = (cnt-1)*x+y;
	else ans = cnt*y;
	if(cnt == 0)ans = 0;
	cout<<ans<<endl;
}