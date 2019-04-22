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

ll line(int a,int b,int c,int &x,int &y){
	int d = exgcd(a,b,x,y);
	if(c%d == 0){
		int k = c/d;x*=k;y*=k;
		return true;
	}
	return false;
}

typedef struct Matrix{
	ll val[2][2];
	Matrix(){ clr(val,0);} 
}Matrix;

Matrix I,O,A,t1;


int N = 2;
Matrix mult(Matrix A,Matrix B){
	Matrix ans = O;
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			for(int k = 0;k<N;k++){
				ans.val[i][j] = (ans.val[i][j]+A.val[i][k]*B.val[k][j])%mod;
				//cout<<ans.val[i][j]<<endl;
			}
		}
	}
	return ans;
}

Matrix qmpow(Matrix A,int p){
	Matrix ans = I;
	while(p){
		if(p&1)ans = mult(ans,A);
		A = mult(A,A);
		p>>=1;
	}
	return ans;
}


void init(){
	O = Matrix();
	I = Matrix();
	for(int i = 0;i<N;i++)I.val[i][i] = 1;
	t1.val[0][0] = 1;
	t1.val[0][1] = 1;
	t1.val[1][0] = 1;
	t1.val[1][1] = 0;
}


int main(){
	ll n;
	init();

	
	while(cin>>n&&n!=-1){
		Matrix x = qmpow(t1,n);
		cout<<x.val[0][1]<<endl;
	}
	
	return 0;
	
}



