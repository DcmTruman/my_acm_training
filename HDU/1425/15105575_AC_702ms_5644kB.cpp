#include<iostream>
#include<stdio.h>
#include<time.h>
#include<algorithm>

using namespace std;


int binsearch(int a[],int n,int k)
{
	int low = 0;
	int high = n-1;
	int mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(a[mid]<k)low = mid+1;
		else high = mid-1;
	}
	return mid;
}


int main()
{
	int m,n;
	int a[1000020];
	while(~scanf("%d%d",&n,&m))
	{
		for(int i = 0;i<n;i++)scanf("%d",&a[i]);
		sort(a,a+n);
		for(int i = n-1;i>n-1-m;i--)
		{
			if(i == n-1)printf("%d",a[i]);
			else printf(" %d",a[i]);
		}
		printf("\n");
		
	}
}
	