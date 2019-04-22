#include<iostream>
#include<map>
#include<string>
using namespace std;

map<char,int>M;
char N[30];

int main()
{
	for(int i=0;i<26;i++)
	{
		char a;
		cin>>a;
		M[a] = i;
	}
	for(int i=0;i<26;i++)
	{
		cin>>N[i];
	}
	string s;
	cin>>s;
	for(int i =0;i<s.length();i++)
	{
		if(s[i]<=90&&s[i]>=65)s[i] = N[M[s[i]+32]]-32;
		else if(s[i]>=97&&s[i]<=122)s[i] = N[M[s[i]]];
	}
	cout<<s<<endl;
}