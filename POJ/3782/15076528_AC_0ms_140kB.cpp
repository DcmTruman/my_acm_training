#include <iostream>
using namespace std;
const int maxN=10024;
int a[maxN],n;
int test(int mid)
{
int i,sum=0;
for(i=1;i<=n;++i){
sum+=a[i];
if(sum==mid)
sum=0;
else if(sum<mid)
continue;
else
return 0;
}
if(sum!=0)
return 0;
return 1;
}
int main()
{
int cases,cases_num,ans;
scanf("%d",&cases);
while(cases--){
int i,sum=0;
scanf("%d%d",&cases_num,&n);
for(i=1;i<=n;++i){
scanf("%d",&a[i]);
sum+=a[i];
}
for(i=0;i<=sum;++i)
if(test(i)==1){
ans=i;
break;
}
printf("%d %d\n",cases_num,ans);
}
return 0;
} 