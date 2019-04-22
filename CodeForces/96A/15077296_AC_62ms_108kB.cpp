#include <stdio.h>
#include <string.h>
int main()
{
	char s[110];
	while(scanf("%s",s)!=EOF)
	{
	int size=strlen(s);
	int cnt=1;
	for(int i=0;i<size;i++)
	{
	if(s[i]==s[i+1])
	{
	cnt++;
	}
	if(cnt>=7)
	{
	printf("%YES\n");
	break;
	}
	if(s[i]!=s[i+1])
	{
	cnt=1;
	}
	}
	if(cnt<7)
	{
	printf("NO\n");
	}
	}
	return 0;
}