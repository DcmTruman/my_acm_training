#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
	int T,n;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&n);
		printf("Case #%d: %d.0000000000\n",t,n-1);
	}
	return 0;
}