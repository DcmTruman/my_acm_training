#include<iostream>
#include<stdio.h>
#include<time.h>
#include<algorithm>
#include<string>
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
    int n;
    while(scanf("%d",&n),n!=0)
    {
        int ans=0,x;
        while(n--)
        {
            scanf("%d",&x);
            ans^=x;//异或用法，满足交换律
        }
        printf("%d\n",ans);
    }
    return 0;
}









	