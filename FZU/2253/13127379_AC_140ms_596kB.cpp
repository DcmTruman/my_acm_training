#include<stdio.h>
#include<string.h>
#include<cstring>
#include<string>
int a;

int aaa[100020];
int ans, max, temp;
int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		ans = 0;
		max = -100020;
		temp = 0;
		//memset(aaa, 0, sizeof(aaa));
		for (int i = 0; i<N; i++)
		{
			scanf("%d", &a);
			ans += a;
			if (a == 1)
			{
				//ans++;
				aaa[i] = -1;
			}
			else
			{
				aaa[i] = 1;
			}
		}
		if (ans == N)
		{
			printf("%d\n", ans - 1);
			continue;
		}
		for (int i = 0; i<N; i++)
		{
			temp = temp + aaa[i];
			if (temp>max)
			{
				max = temp;
			}
			if (temp<0)
			{
				temp = 0;
			}
		}
		//ans = ans + max;
		printf("%d\n", ans+max);
	}
}