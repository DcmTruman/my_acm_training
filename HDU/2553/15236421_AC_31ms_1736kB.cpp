#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,ans;
int map[15];
int visit[15];
int sol[15];
void dfs(int k)
{
	int i,j,flag;
	if(k==n+1)
	{
		ans++;
		return;
	}
	for(i=1;i<=n;i++)
	if(!visit[i])  //各行棋子不能在同一竖
	{
		map[k]=i;
		flag=1;
		for(j=1;j<=k-1;j++)  //判断是否在同一斜线上
		if((map[k]-map[j])==(k-j)||(map[k]-map[j])==(j-k))
		{
			flag=0;
			break;
		}
		if(flag)
		{
			visit[i]=1;
			dfs(k+1);
			visit[i]=0;  //释放第i列，进行下一次搜索
		}
	}
}
int main()
{
	int i;
	for(i=1;i<=10;i++)
	{
		ans=0;
		n=i;
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		dfs(1);
		sol[i]=ans;
	}
	while(scanf("%d",&n),n)
	printf("%d\n",sol[n]);
	return 0;
}