#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<string>
#include<queue>
#include<vector>
#include<math.h>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck:"<<__LINE__<<endl;
using namespace std;

typedef long long ll;

ll D[30];

void init(){
	D[0] = 1;
	D[1] = 0;
	D[2] = 1;
	for(ll i = 3;i<=30;i++){
		D[i] = (i-1)*(D[i-1]+D[i-2]);
	}
	
}

ll C(int n,int m)
{
    ll ans=1;
    for(ll i=1;i<=m;i++)ans=ans*(n--)/i;
    return ans;
}


int main(){
	init();
	int n;
	ll ans = 0;
	while(cin>>n&&n!=0)
	{	
		ans = 0;
		for(int i = 0;i<=n/2;i++){
			//cout<<n<<" "<<i<<" "<<C(n,i)<<endl;
			ans += D[i]*C(n,i);
			//cout<<D[i]<<endl;
		}
		cout<<ans<<endl;
	}
	
	return 0;
	
}



