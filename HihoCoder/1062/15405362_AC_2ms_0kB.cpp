#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<map>
#include<vector>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck"<<endl;
#define LSon(x) 2*(x)
#define RSon(x) 2*(x)+1

using namespace std;
typedef long long ll;

map<string,string>tree;
vector<string>s1;
vector<string>s2;
int n;
string a,b;

int main()
{
	cin>>n;
	while(n--){
		cin>>a>>b;
		tree[b] = a;
	}
	cin>>n;
	while(n--){
		cin>>a>>b;
		s1.clear();
		s2.clear();
		s1.push_back(a);
		s2.push_back(b);
		while(tree.count(a)){
			a = tree[a];
			s1.push_back(a);
		}
		while(tree.count(b)){
			b = tree[b];
			s2.push_back(b);
		}
		bool flag = false;
		int i,j;
		for(i = 0;i<s1.size();i++){
			for(j = 0;j<s2.size();j++){
				if(s1[i] == s2[j]){
					flag = true;
					break;
				}
			}
			if(flag)break;
		}
		if(flag)cout<<s1[i]<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
} 
