#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
	int T,n,m,a,b,c,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d",&n,&m,&a,&b);
		ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&c);
				if(c>b||c<a) ans++;
			}
		}
		if(a>b){
			printf("No Solution\n");
			continue;
		}
		printf("%d\n",ans);
	}
	return 0;
}
