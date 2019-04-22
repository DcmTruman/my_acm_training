#include<iostream>
#include<stdio.h>
#include<time.h>
#include<algorithm>
#include<string.h>
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
	char s[120];
	while(~scanf("%s",s))
	{
		int len = strlen(s);
		int max = -1;
		for(int i = 0;i<len;i++)
		{
			if(int(s[i])>max)max = int(s[i]);
		}
		for(int i = 0;i<len;i++)
		{
			printf("%c",s[i]);
			if(int(s[i]) == max)printf("(max)");
		}
		printf("\n");
	}
	
}
	