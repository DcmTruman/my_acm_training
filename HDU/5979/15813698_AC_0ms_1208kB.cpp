#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const double PI=acos(-1);

int main()
{
	int n,r,t;
	double ans,sum;
	while(scanf("%d %d",&n,&r)!=EOF){
		ans=0.0;
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			sum=0.5*r*r*sin(PI*t/180.0);
			ans+=sum;
		}
		printf("%.3f\n",ans);
	}
	return 0;
}
