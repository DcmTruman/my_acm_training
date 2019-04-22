#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n,i,j,l,r,x;
	while(cin>>n)
	{
		for(int i = 1;i<=n;i++)
		{
			cin>>x;
			if(x == 1)l = i;
			else if(x == n)r = i;	
		}
		if(l>r)cout<<l-r+max(n-l,r-1);
		else cout<<r-l+max(n-r,l-1);	
	} 
	
	return 0;
}