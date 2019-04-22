#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long a[64];
int main()
{
	int T,k;
	long long n;
	bool flag;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%lld %d",&n,&k);
		flag=false;
		if(n%2==0){
			n-=1; flag=true;
		}
		for(int i=0;i<k;i++){
			a[i]=(n>>i)&1LL;
		}
		printf("Case #%d:\n",t);
		for(int i=0;i<k-1;i++){
			if(a[i+1]==0){
				printf("%lld -\n",1LL<<i);
			}else{
				printf("%lld +\n",1LL<<i);
			}
		}
		if(flag==true){
			printf("%lld +\n",(1LL<<(k-1))+1);
		}else{
			printf("%lld +\n",1LL<<(k-1));
		}
	}
	return 0;
}
