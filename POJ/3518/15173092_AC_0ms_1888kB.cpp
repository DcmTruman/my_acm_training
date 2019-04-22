#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long ll;

const int maxn = 1300000;

bool isp[maxn];
int pr[maxn];
int k = 0;

void init()
{
	memset(isp,1,sizeof(isp));
	isp[0] = false;
	isp[1] = false;
	for(int i = 2;i<maxn;i++)
	{
		if(isp[i])
		{
			pr[k++] = i;
			for(int j = i+i;j<maxn;j += i)
			{
				isp[j] = false;
			}
		}
	}
}
int main()
{
	init();
	int n;
	while(cin>>n&&n)
	{
		if(isp[n])cout<<"0"<<endl;
		else
		{
			int p = lower_bound(pr,pr+k,n) - pr;
			cout<<pr[p] - pr[p-1]<<endl;
		}
	}


	
	
}