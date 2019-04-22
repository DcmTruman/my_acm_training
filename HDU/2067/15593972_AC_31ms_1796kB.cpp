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
ll K[50];

void init(){
	
	K[0] = 1;
	K[1] = 1;
	for(ll n = 2;n<50;n++){
		for(ll i = 0;i<=n-1;i++){
			K[n] += K[i]*K[n-i-1];
		}
	}
}



int main(){
	init();
	int n;
	int t = 0;
	while(cin>>n&&n!=-1)
	{	
		t++;
		cout<<t<<" "<<n<<" "<<2*K[n]<<endl;
	}
	
	return 0;
	
}



