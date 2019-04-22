#include<stdio.h>
#include<string.h>
using namespace std;
long long a[1010][1010];
int main(){
	int n,m;
	long long x,y,delta,sum;
	bool flag;
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%lld %lld",&x,&y);
				a[2*i][2*j+1]=x; a[2*i+1][2*j]=y;
			}
		}
		flag=true;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[2*i+1][2*j]==0) continue;
				delta=a[2*i+1][2*j];
				a[2*i+1][(2*j+2)%(2*m)]+=delta; //right
				a[2*i][2*j+1]+=delta; //up
				a[2*i+1][2*j]-=delta; //left
				a[(2*i+2)%(2*n)][2*j+1]-=delta; //down
			}
			if(a[2*i+1][0]!=0){
				flag=false; break;
			}
		}
		sum=0;
		for(int i=0;i<n;i++){
			for(int j=1;j<m;j++){
				if(a[2*i][2*j+1]!=a[2*i][1]){
					flag=false; break;
				}
			}
			if(flag==false) break;
			sum+=a[2*i][1];
		}
		if(sum!=0) flag=false;
		if(flag==true) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}