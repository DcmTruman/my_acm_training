#include<iostream>
#include<string.h>
#include<algorithm>
#define clr(x) memset(x,0,sizeof(x))

using namespace std;
 
int r,n;
int aa[1005];

int main(){
	while(cin>>r>>n){
		if(r == -1 && n == -1)break;
		clr(aa);
		for(int i = 0;i < n ; i++)cin>>aa[i];
		sort(aa,aa+n);
		int i = 0;
		int ans = 0;
		while(i<n){
			int t = aa[i];
			while(aa[i]-t<=r&&i<n)i++;
			i--;
			t = aa[i];
			while(aa[i]-t<=r&&i<n)i++;
			ans++;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}