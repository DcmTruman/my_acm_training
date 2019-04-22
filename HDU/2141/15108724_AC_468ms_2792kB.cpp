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
	int L,M,N;
	int S,X;
	int a[520],b[520],c[520];
	int ab[250020];
	int T = 0;
	while(cin>>L>>M>>N)
	{
		T++;
		for(int i = 0;i<L;i++)cin>>a[i];
		for(int i = 0;i<M;i++)cin>>b[i];
		for(int i = 0;i<N;i++)cin>>c[i];
		int cnt = 0;
		for(int i = 0;i<L;i++)
		{
			for(int j = 0;j<M;j++)
			{
				ab[cnt++] = a[i]+b[j];
			}
		}
		sort(ab,ab+cnt);
		cin>>S;
		int ans = false;
		cout<<"Case "<<T<<":"<<endl;
		for(int i = 0;i<S;i++)
		{
			ans = false;
			cin>>X;
			for(int i = 0;i<N;i++)
			{
				int k = c[i];
				int low = 0;
				int high = cnt-1;
				int mid;
				while(low<=high)
				{
					mid = (low+high)/2;
					if(ab[mid]+k == X){
						ans = true;
						break;
					}
					if(ab[mid]+k<X)low = mid+1;
					else high = mid-1;
				}
				if(ans)break;
			}
			if(ans)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		
	}
}









	