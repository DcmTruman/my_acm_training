#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const long long mod=1e9+7;
const int MAXN=1e6;
long long sum[MAXN+10],fac[MAXN+10];
long long inv[MAXN+10],invfac[MAXN+10];

void solve(){
	sum[0]=0; fac[0]=1; inv[0]=0;
	sum[1]=0; fac[1]=1; inv[1]=1;
	invfac[0]=0; invfac[1]=1;
	for(int i=2;i<=MAXN;i++){
		sum[i]=sum[i-1]+i;
		fac[i]=(fac[i-1]*i)%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		invfac[i]=(invfac[i-1]*inv[i])%mod;
	}
	return ;
}

int main()
{
	long long T,n,k,r;
	long long ans;
	solve();
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		if(n<=4){
			printf("%lld\n",n); continue;
		}
		k=upper_bound(sum,sum+MAXN,n)-sum-1;
		r=n-sum[k];
		//printf("k=%d rest=%d\n",k,r);
		if(r==k){
			ans=(fac[k]*invfac[2])%mod;
			ans=(ans*(k+2))%mod;
		}else{
			ans=(fac[k+1]*invfac[k-r+1])%mod;
			ans=(ans*fac[k-r])%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
