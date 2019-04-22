#include <iostream>
#include <stdio.h>

using namespace std;
int n;

int dfs(int nown,int nowb)
{
	int cnt = 0;
	if(nown == 0)return 1;
	if(nown == nowb)return 1;
	if(nown < nowb)return 0;
	for(int i = nowb;i<=nown;i++)
	{
		if(nown - i >= i || nown - i == 0)cnt += dfs(nown - i , i);
	}
	return cnt;
}
int main()
{
	while(~scanf("%d",&n))
	{
		printf("%d\n",dfs(n,1));
	}
}
