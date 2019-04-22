#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXN=1e5;
long long a[MAXN+10],b[MAXN+10];
long long Abs(long long x){
	return x<0? -x:x;
}
int main(){
	int m;
	bool flag;
	long long T,n,Low,High,res,len,dx,dy,bmn,bmx;
	while(scanf("%lld %lld %d",&T,&n,&m)!=EOF){
		for(int i=0;i<m;i++){
			scanf("%lld %lld",&a[i],&b[i]);
		}
		res=(a[0]-1)*a[0]/2;
		if(b[0]>=a[0]) Low=b[0]*a[0]-res;
		else Low=(b[0]+1)*b[0]/2;
		High=b[0]*a[0]+res;
		flag=true;
		//printf("Low : %lld High : %lld\n",Low,High);
		for(int i=1;i<m;i++){
			Low+=b[i]; High+=b[i];
			if(Abs(b[i]-b[i-1])>a[i]-a[i-1]){
				flag=false; break;
			}
			if(a[i-1]+1==a[i]) continue;
			dx=a[i]-a[i-1]-1; dy=Abs(b[i]-b[i-1]);
			//printf("dx=%lld dy=%lld\n",dx,dy);
			bmn=min(b[i],b[i-1]); bmx=max(b[i],b[i-1]);
			
			if((dx-dy)>=2*(bmn-1)){
				res=bmn*dy+dy*(dy-1)/2;
				res+=bmn*(bmn-1);
			}else{
				res=bmn*dx+dy*(dy-1)/2;
				len=(dx-dy)/2; res-=len*(len+1);
				if((dx-dy)%2==1) res-=(len+1);
			}
			//printf("Low : %lld ",res);
			Low+=res;
			
			res=bmn*dx+dy*(dy+1)/2;
			len=(dx-dy)/2; res+=len*(len+1);
			if((dx-dy)%2==1) res+=(len+1);
			res+=(dx-dy)*dy;
			//printf("High : %lld\n",res);
			High+=res;
			
		}
		long long oldL=Low,oldH=High;
		res=(n-a[m-1]+1)*(n-a[m-1])/2;
		if(b[m-1]>n-a[m-1]) Low+=b[m-1]*(n-a[m-1])-res;
		else Low+=(b[m-1]-1)*b[m-1]/2;
		High+=b[m-1]*(n-a[m-1])+res;
		//printf("Low : %lld High : %lld\n",Low-oldL,High-oldH);
		//printf("debug <%lld,%lld> %lld %d\n",Low,High,T,flag);
		if(flag==true && T>=Low && T<=High){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}