#include<iostream>
#include<stdio.h>
#include<time.h>
#include<algorithm>
#include<string>
#include<map>
typedef long long LL;
using namespace std;


int binsearch(int a[],int n,int k)
{
	int low = 0;
	int high = n-1;
	int mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(a[mid] == k){
		return mid;
	}
		if(a[mid]<k)low = mid+1;
		else high = mid-1;
	}
	return -1;
}

int dg(int a)
{
	//cout<<a<<endl;
	if(a <= 0)return 1;
	int ans = 0;
	for(int i = 1;i<=a;i++)
	{
		ans += dg(a-i);
	}
	return ans;
}


map<LL ,LL>M;

int main()
{
	LL n;
	cin>>n;
	LL a[100020];
	LL sum = 0;
	LL t;
	LL ans = -1;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
		sum += a[i];
		M[sum]++;
		ans = max(ans,M[sum]);
	}
	cout<<n-ans<<endl;
	
	
}











	