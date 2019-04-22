#include<stdio.h>

int main()
{
	int N;
	while (scanf("%d",&N) != EOF)
	{
		int temp1 = 0, temp2 = 0;
		for (int i = 0; i < N; i++) {
			int a;
			scanf("%d", &a);
			if (((i & 1) && a) || ((!(i & 1)) && (!a)))temp1++;
			if (((i & 1) && (!a)) || (!(i & 1) && (a)))temp2++;
		}
		printf("%d\n", (temp1<temp2)?temp1:temp2);
	}
}