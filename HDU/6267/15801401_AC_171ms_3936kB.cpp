#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const long long mod=998244353;
long long inv[100005],invfac[100005],fac[100005];
int a[100005];

void getInv(){
	inv[1]=1; fac[0]=1; fac[1]=1;
	invfac[0]=1; invfac[1]=1;
	for(long long i=2;i<=100000;i++){
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		invfac[i]=invfac[i-1]*inv[i]%mod;
		fac[i]=fac[i-1]*i%mod;
	}
}


int main()
{
	int T,n;
	long long num,dec,k;
	getInv();
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		k=1; num=a[1]; dec=invfac[n];
		for(int i=2;i<=n;i++){
			num=num*(i-1)%mod;
			num=(num+((k+fac[i-1])%mod)*a[i])%mod;
			k=(k*i+fac[i-1])%mod;
		}
		printf("%lld\n",num*dec%mod);
	}
	return 0;
}
