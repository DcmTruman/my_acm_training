#include <stdio.h>
#include <string.h>
int main()
{
char a[1000],b[1000];
int i;
while(~scanf("%s",a))
{
int len=strlen(a),j=0;
for(i=0;i<len;i++)
if(a[i]>='A'&&a[i]<='Z')a[i]+=32;  
for(i=0;i<len;i++)
if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y')
continue;
else b[j++]=a[i];
for(i=0;i<j;i++)
printf(".%c",b[i]);
printf("\n");
}
return 0;
}