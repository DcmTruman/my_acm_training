#include <iostream>
#include <stdio.h>
#include <istream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <string.h>
#define ll long long
using namespace std;
const int maxn = 1000020;
ll pre[maxn];
ll ps[maxn];
char s[maxn];
int now = 1;
ll solve(ll m)
{
	//cout << "--------------------" << m << endl; 
	int pos = 1;
	ll ret = 0;
	int cnt = 0;
	//cout << now << endl;
	while(pos<=now){
		//cout <<"fuck"<<endl;
		if(!(pos-1)){
			cnt ++;
			ret += pre[1] -1;
			pos = upper_bound(ps+1,ps+now+1,m+ps[pos-1])-ps;
			//cout << pos <<endl;
			ret += pre[pos] - 1;
		}else{
			cnt++;
			pos = upper_bound(ps+1,ps+now+1,m+ps[pos-1])-ps;
			//cout << pos <<endl;
			ret += pre[pos] - 1;
		}
	
	}
	return ret+cnt;
}
int main()
{

	char c;
	int tpp;
	int cnt = 0;
	while((c = getchar())!='\n'){
		if(c == ' '){
			pre[now]++;
			now++;
		}else{
			pre[now]++;
		}
	}
	pre[now]++;
	for(int i = 1;i<=now;i++){
		ps[i] = ps[i-1] + pre[i];
		//cout << ps[i] << " ";
	}//cout << endl;


	//cout << now << endl;
	ll a,b;
	scanf("%lld%lld",&a,&b);
	for(int i = a;i<=b;i++){
		printf("%lld\n",solve(i+1));
	}	
} 