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

string s;

int main(){
	cin>>s;
	if(s.length() == 1){
		if((s[0]-'0')%4 == 0)cout<<"4"<<endl;
		else cout<<"0"<<endl;
	}
	else{
		int a = ((s[s.length()-2]-'0')*10+s[s.length()-1]-'0');
		if(a%4 == 0)cout<<"4"<<endl;
		else cout<<"0"<<endl;
	}
	
}




