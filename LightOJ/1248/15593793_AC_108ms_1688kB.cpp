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
int mod =  10000;
ll qpow(ll a,ll n){
	ll ans = 1;
	while(n>0){
		if(n&1)ans = (ans*a);
		a = (a*a);
		n>>=1;
	}
	//cout<<a<<","<<ans<<endl;
	return ans;
}

ll exgcd(int a,int b,int &x,int &y){
	if(a==0&&b==0)return -1;
	if(b==0){
		x = 1;y = 0;
		return a;
	}
	int ans = exgcd(b,a%b,y,x);
	y -= a/b*x;
	return ans;
}

ll gcd(ll a,ll b){
	return (b!=0)?gcd(b,a%b):a;
} 




int main(){
	int T;
	cin>>T;
	for(int tt = 1;tt<=T;tt++){
		double ans;
		int n;
		cin>>n;
		ans = n;
		for(double  i = 1;i<=n-1;i++){
			ans += (i/n)/(1-(i/n)); 
		}
		printf("Case %d: %.10lf\n",tt,ans);
	}
	
	return 0;
	
}



