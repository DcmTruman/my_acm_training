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
int mod =  5;
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

ll line(int a,int b,int c,int &x,int &y){
	int d = exgcd(a,b,x,y);
	if(c%d == 0){
		int k = c/d;x*=k;y*=k;
		return true;
	}
	return false;
}


int main(){
	double ans;
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	ans = a/b/(1-(1-a/b)*(1-c/d));

	printf("%.12lf",ans);
	
	return 0;
	
}



