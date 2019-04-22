#include <iostream>
using namespace std;

const int maxn = 10020;

int a[maxn],n;

bool isOK(int aa)
{
	int sum = 0;
	for(int i = 1;i<=n;i++)
	{
		sum += a[i];
		//cout<<"Debug:"<<sum<<" "<<aa<<endl;
		if(sum == aa)sum = 0;
		else if(sum<aa)continue;
		else return false;
	}
	if(sum != 0)return false;
	return true;
	
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int c,sum = 0,ans;
		cin>>c>>n;
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i];
			sum += a[i];
		}
		for(int i = 0;i<=sum;i++)
		{
			if(isOK(i))
			{
				ans = i;
				break;
			}
		}
		cout<<c<<" "<<ans<<endl;
	}
}
