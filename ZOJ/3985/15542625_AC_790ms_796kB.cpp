#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<string>
#include<queue>
#include<vector>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck:"<<__LINE__<<endl;
using namespace std;

const int maxn = 2e5+20;

int n;
string s;

int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		cin>>n;
		cin>>s;
		int ans = 0;
		bool flag = false;
		
		for(int i = 0;i<n;i++){
			if(i<n-4){
				string s1 = s.substr(i,5);
				if(s1 == "CCCPC"){
					i += 3;
					ans ++;
					continue;
				}
			}
			if(i<n-3){
				string s1 = s.substr(i,4);
				if(s1 == "CCPC"){
					i += 2;
					ans += 1;
					//continue;
				}
			}
			if(i<n-2&&!flag){
				string s1 = s.substr(i,3);
				if(s1 == "CCC"||s1 == "CPC"||s1 == "CCP")flag = true;
			}
		}
		if(flag)ans += 1;
		cout<<ans<<endl;
	}

}


/* 
8
CCCCCCPC

*/


