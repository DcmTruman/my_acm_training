#include<iostream>
#include<string.h>
#include<algorithm>
#define clr(x) memset(x,0,sizeof(x))

typedef long long ll;
using namespace std;

const int maxn = 1e5+7;

int n;
ll aa[2*maxn];
int main()
{
	cin>>n;
	for(int i =1;i<=2*n;i++)cin>>aa[i];
	sort(aa+1,aa+1+2*n);
	ll ans = (aa[n]-aa[1])*(aa[2*n]-aa[n+1]);
	for(int i = 2;i<=n;i++)
	{
		ll t = aa[n+i-1]-aa[i];
		ans = min(ans,t*(aa[2*n]-aa[1]));
	}
	cout<<ans<<endl;
return 0;
}