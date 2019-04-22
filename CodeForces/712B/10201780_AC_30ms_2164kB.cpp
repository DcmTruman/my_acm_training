#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int l=0,r=0,u=0,d=0;
	string s;
	cin>>s;
	if(s.length()&1){cout<<"-1"<<endl;return 0;}
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='R')r++;
		if(s[i]=='L')l++;
		if(s[i]=='U')u++;
		if(s[i]=='D')d++;
	}
	int a = min(r,l);
	r -=a;
	l -=a;
	int b = min(u,d);
	u -= b;
	d -= b;
	int temp = r+l+u+d;
	cout<<temp/2<<endl;
}