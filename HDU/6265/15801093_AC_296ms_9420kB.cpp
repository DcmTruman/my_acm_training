#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXN=1<<20;
long long a[24],p[24],inv[24];
long long num[MAXN+10];
const long long mod=998244353;
long long qPow(long long x,long long s){
	long long ans=1;
	while(s){
		if(s&1) ans=ans*x%mod;
		x=x*x%mod;
		s>>=1;
	}
	return ans;
}

int lowbit(int x){
	return x&(-x);
}

long long getInv(long long x){
	if(x==1) return 1;
	return (mod-mod/x)*getInv(mod%x)%mod;
}

int main()
{
	int T,m,total;
	long long n,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&m);
		n=1;
		for(int i=0;i<m;i++){
			scanf("%lld %lld",&a[i],&p[i]);
			n=(n*qPow(a[i],p[i]))%mod;
			inv[i]=getInv(a[i]);
		}
		num[0]=n; ans=n;
		total=(1<<m);
		for(int x=1;x<total;x++){
			for(int j=0;j<m;j++){
				if((x>>j)&1){
					num[x]=num[x-lowbit(x)]*p[j]%mod;
					num[x]=num[x]*(a[j]-1)%mod;
					num[x]=num[x]*inv[j]%mod;
					ans=(ans+num[x])%mod;
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
