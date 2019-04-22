#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#define LL long long
#define MAXN 1000010
using namespace std;
int main()
{
    LL ans,n;
	while(cin>>n)
	{
		if(n<=2)
		{
			ans=n;
		}
		else if(n%2)
		{
			ans=n*(n-1)*(n-2);
		}
		else
		{
			if(n%3)
			{
				ans=n*(n-1)*(n-3);
			}
			else
			{
				ans=(n-1)*(n-2)*(n-3);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 