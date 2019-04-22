#include <iostream>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 1e5+7;
ll arr[maxn];
ll brr[maxn];
ll dpy[2][maxn];
ll dpz[2][maxn];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n-1;i++){
		scanf("%I64d",&arr[i]);
	}
	int cnt = 1;
	dpy[0][n] = 0;//hui
	dpy[1][n] = 0;//buhui
	for(int i = n-1;i>=1;i--)
	{
		if(arr[i]&1)
		{
			if(arr[i] == 1)dpy[0][i] = 0;
			else
			{
				dpy[0][i] = arr[i] - 1 + dpy[0][i+1];
			}
			dpy[1][i] = arr[i] + max(dpy[0][i+1],dpy[1][i+1]);
		}
		else
		{
			dpy[0][i] = arr[i] + dpy[0][i+1];
			dpy[1][i] = arr[i]-1 + max(dpy[0][i+1],dpy[1][i+1]);
		}
	}
	dpz[0][1] = 0ll;
	dpz[1][1] = 0ll;
	for(int i = 2;i<=n;i++)
	{
		if(arr[i-1]&1)
		{
			if(arr[i-1] == 1)dpz[0][i] = 0;
			else
			{
				dpz[0][i] = arr[i-1] - 1 + dpz[0][i-1];
			}
			dpz[1][i] = arr[i-1] + max(dpz[0][i-1],dpz[1][i-1]);
		}
		else
		{
			dpz[0][i] = arr[i-1] + dpz[0][i-1];
			dpz[1][i] = arr[i - 1]-1 + max(dpz[0][i-1],dpz[1][i-1]);
		}
	}
	ll mx = -INF;
//	printf("ydebug:\n");
//	for(int i = 1;i<=n;i++){
//		printf("i = %d hui : %I64d buhui: %I64d\n",i,dpz[0][i],dpz[1][i]);
//	}
	for(int i = 1;i<=n;i++)
	{
		//printf("debug : i = %d mx = %I64d\n",i,mx);
//		if(i == 6)
//		{
//			printf("left = %I64d,right = %I64d\n",dpz[0][i],max(dpy[0][i],dpy[1][i]));
//		}
		mx = max(mx,dpz[0][i] + max(dpy[0][i],dpy[1][i]));
		//printf("debug : i = %d mx = %I64d\n",i,mx);
		mx = max(mx,dpy[0][i] + max(dpz[0][i],dpz[1][i]));
	}
	printf("%I64d\n",mx);
}