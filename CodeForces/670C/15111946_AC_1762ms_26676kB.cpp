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
	LL audio[200020];
	LL sub[200020];
	LL temp;
	LL n,m;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>temp;
		M[temp]++;
	}
	cin>>m;
	for(int i = 1;i<=m;i++)cin>>audio[i];
	
	for(int i = 1;i<=m;i++)cin>>sub[i];
	
	
	LL a1 = 0,a2 = 0,index = 1;
	
	for(int i = 1;i<=m;i++)
	{
		if(a1<M[audio[i]])
		{
			a1 = M[audio[i]];
			a2 = M[sub[i]];
			index = i;
		}
		else if(a1 == M[audio[i]]&&a2<M[sub[i]])
		{
			a1 = M[audio[i]];
			a2 = M[sub[i]];
			index = i;
		}
	}
	cout<<index<<endl;
	
}











	