#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long a[10]={1,9,41,109,205,325,473,649,853};
int main(){
	int T;
	unsigned long long n,ans;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%llu",&n);
		if(n<=7){
			printf("Case #%d: %lld\n",t,a[n]);
		}else{
			ans=649LL+(204LL+14*(n-8))*(n-7);
			printf("Case #%d: %llu\n",t,ans);
		}
	}
	return 0;
}

