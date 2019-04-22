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
		if(n&1)ans = (ans*a)%mod;
		a = (a*a)%mod;
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

int num = 0;
int n;
ll cc[120];
int main(){
	cin>>n;
	bool flag = false;
	int k = 0;
	for(int i = 0;i<120;i++)cc[i] = 1;
	for(int i = 0;i<n;i++){
		int a;cin>>a;
		if(a == 1&&!flag){
			//fuck
			flag = true;
			num++;
		}
		else if(a == 0&&flag){
			cc[k]++;
		}
		else if(a == 1&&flag){
			num++;
			k++;
		}
		
	}
	ll ans = 1;
	if(num == 0)cout<<"0\n";
	else if(num == 1)cout<<"1\n";
	else{
		for(int i = 0;i<k;i++){
			ans *= cc[i];
		}
		cout<<ans<<endl;
	}
	
	return 0;
	
}



