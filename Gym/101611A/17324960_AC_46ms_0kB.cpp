#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int INF=1e9+7;
int solve(int x,int y,long long n){
	int res=1;
	long long f=x,m=0;
	while(f<=(n-f)/2){
		res+=1; f<<=1LL;
		//printf("<>> %d %lld\n",res,f);
	}
	m=n-f;
	//printf("debug %d %d %d %lld\n",x,y,res,m);
	while(m>y){
		res+=1; m=(m/2)+(m%2);
	}
	return res;
}
int main(){
	long long n;
	int k,ans;
	while(scanf("%lld %d",&n,&k)!=EOF){
		if(k>=n || n==1){
			printf("1\n");
			continue;
		}
		ans=INF;
		for(int i=1;i<k;i++){
			ans=min(ans,solve(i,k-i,n));
		}
		printf("%d\n",ans);
	}
	return 0;
}
// 1000000000000000000 2