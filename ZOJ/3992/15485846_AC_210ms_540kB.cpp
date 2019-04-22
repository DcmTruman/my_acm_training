#include<iostream>
#include<string>
#include<string.h>
#include<stack>
#include<vector>
#include<cstdio>
#include<algorithm>
#define clr(x,b) memset(x,(b),sizeof(x))
using namespace std;

string s;
int m,n;
int main()
{
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		cin>>s;
		int ln = 0;
		int rn = 0;
		for(int i = 1;i<m;i++){
			if(s[i] == 'R')rn++;
		}
		for(int i = m-1;i<n-1;i++){
			if(s[i] == 'L')ln++;
		}
		cout<<min(rn,ln)<<endl;
	}
	
}

