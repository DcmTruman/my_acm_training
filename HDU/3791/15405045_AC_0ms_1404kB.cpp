#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck"<<endl;
#define LSon(x) 2*(x)
#define RSon(x) 2*(x)+1

using namespace std;
typedef long long ll;


int tr[1020];
int tr1[1020];
int n;
int j;
string s;


int main()
{
	while(cin>>n){
		cin>>s;
		clr(tr,-1);
		for(int i = 0;i<s.length();i++){
			j = 1;
			while(tr[j]!=-1){
				if(s[i]-'0'<tr[j])j = LSon(j);
				else j = RSon(j);
			}
			tr[j] = s[i]-'0';
		}
		while(n--){
			cin>>s;
			clr(tr1,-1);
			for(int i = 0;i<s.length();i++){
				j = 1;
				while(tr1[j]!=-1){
					if(s[i]-'0'<tr1[j])j = LSon(j);
					else j = RSon(j);
				}
				tr1[j] = s[i]-'0';
			}	
			for( j = 0;j<=1000;j++){
				if(tr1[j]!=tr[j])break;
			}
			if(j>1000)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		
	}
	return 0;
} 
