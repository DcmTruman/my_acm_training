#include<stdio.h>
int main()
{
	int n;
	long long sum,max;
	int Case = 1;
	while(scanf("%d",&n) != EOF)
	{
		max = 0;
		int Num[20];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&Num[i]);
		}
		for(int i =0;i<n;i++)
		{
			for(int j =i;j<n;j++)
			{
				sum = 1;
				for(int k = i;k<=j;k++)
				{
					sum *=Num[k];
				}
				if(sum>max)
				{
					max = sum;
				}
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n",Case++,max);
	}
}