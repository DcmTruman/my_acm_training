#include <iostream>
#include <stdio.h>

using namespace std;


int dfs(int nowm,int nown)
{
	if(nowm == 0 || nown == 1)return 1;
	return (nowm < nown)?dfs(nowm,nowm) : dfs(nowm-nown,nown) + dfs(nowm , nown-1); 
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		printf("%d\n",dfs(m,n));
	}
}
