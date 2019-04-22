#include<iostream>
#include<stdio.h>
#include<time.h>
#include<algorithm>
#include<string>

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

	
int main()
{
    LL cnt1,cnt2,x,y;
    
    while(cin>>cnt1>>cnt2>>x>>y)
    {
    	LL low = 0;
    	LL high = 1e18;
    	LL mid;
    	while(low<=high)
    	{
    		mid = (low+high)/2;
    		LL a = mid/x;
    		LL b = mid/y;
    		LL c = mid/(x*y);
    		if(mid-a>=cnt1&&mid-b>=cnt2&&mid-c>=cnt1+cnt2)high = mid-1;
    		else low = mid+1;
		}
		cout<<low<<endl;
	}
    
}









	