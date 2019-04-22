#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
bool cmp(string s1,string s2)
{
	return s1+s2<s2+s1;
}
int main()
{
	string STR[50200];
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>STR[i];
	}
	sort(STR,STR+N,cmp);
	for(int i=0;i<N;i++)
	{
		cout<<STR[i];
	}
}