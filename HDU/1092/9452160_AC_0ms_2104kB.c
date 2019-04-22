#include<stdio.h>


int main()
{
	int a, sum,n;
	while (scanf("%d", &n) &&n)
	{
		sum = 0;
		while (n--)
		{
			scanf("%d", &a);
			sum  += a;
		}
	   printf("%d\n", sum);
	}
	system("pause");
	return 0;
}