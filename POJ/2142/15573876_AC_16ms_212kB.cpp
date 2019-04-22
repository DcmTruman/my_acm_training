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
int main(){
	//ax = by+d; 
	//ax-by = d; 
	int a,b,d;
	while(cin>>a>>b>>d){
		if(a == 0&&b==0&&d==0)break;
		int x,y;
		
		if(line(a,b,d,x,y)){
			int k = b/gcd(a,b);
			int k1 = a/gcd(a,b);
			int x0 = (x%k+k)%k;
			int y0 = (d-a*x0)/b;
			int x2 = x -b/gcd(a,b);
			int y2 = y +a/gcd(a,b);
			int y1 = (y%k1+k1)%k1;
			int x1 = (d-b*y1)/a;
			int y3 = y1-a/gcd(a,b);
			int x3 = x1+b/gcd(a,b);
			x0 = abs(x0);y0=abs(y0);x1=abs(x1);y1=abs(y1);x2=abs(x2);y2=abs(y2);x3=abs(x3);y3=abs(y3);
			int aa = abs(x0)+abs(y0);
			int bb = abs(x1)+abs(y1);
			int cc = abs(x2)+abs(y2);
			int dd = abs(x3)+abs(y3);
			int ans1,ans2;
			
			
			
			if(aa<=bb&&aa<=cc&&aa<=dd){
				
				ans1  = abs(x0);
				ans2 = abs(y0);
			} 
			else if(bb<=aa&&bb<=cc&&bb<=dd){
				
				ans1 = abs(x1);
				ans2 = abs(y1);
			}
			else if(cc<=aa&&cc<=bb&&cc<=dd){
				
				ans1 = abs(x2);
				ans2 = abs(y2);
			}
			else if(dd<=aa&&dd<=bb&&dd<=cc){
				
				ans1 = abs(x3);
				ans2 = abs(y3);
			}
			//cout<<x<<" "<<y<<endl;
			cout<<ans1<<" "<<ans2<<endl;
		}
	}
	
}




