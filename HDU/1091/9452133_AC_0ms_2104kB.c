#include<stdio.h>


int main()
{
	int a, b, sum;
	while (scanf("%d %d", &a, &b) &&(a||b))
	{
		sum = a + b;
	   printf("%d\n", sum);
	}
	system("pause");
	return 0;
}