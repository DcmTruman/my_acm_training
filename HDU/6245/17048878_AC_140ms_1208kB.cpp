#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
	int T,x,y,k,ans,res;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d %d %d",&x,&y,&k);
		if(x>y){
			ans=k;
		}else{
			for(int i=0;i<=k;i++){
				res=i*11*x+(k-i)*(9*x-11*y);
				if(res>=0){
					ans=k-i; break;
				}
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}