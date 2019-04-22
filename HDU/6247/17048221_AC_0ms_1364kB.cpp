#include <iostream>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int tt = 1;tt<=T;tt++){
		int n;
		scanf("%d",&n);
		int ans = 0;
		for(int i = 0;i<n;i++){
			int temp;
			scanf("%d",&temp);
			if(temp%10 == 0){
				ans += (temp + temp/10);
			}else{
				ans += (temp + temp/10 + 1);
			}
		}
		printf("Case #%d: %d\n",tt,ans);
	}
}