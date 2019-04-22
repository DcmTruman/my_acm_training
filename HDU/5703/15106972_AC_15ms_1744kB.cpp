
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("1");
		for(int i=1;i<n;i++)
			printf("0");
		printf("\n");
	}
	return 0;
}