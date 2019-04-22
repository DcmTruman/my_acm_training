#include<iostream>
#include<string>

using namespace std ;
int main()
{
	string temp,s;
	cin>>s;
	temp  = s;
	int count =1;
	while(1)
	{
		char c=s[s.length()-1];
		s.insert(0,1,c);
		s = s.substr(0,s.length()-1);
		if(s!=temp)count++;
		else break;
	}
	cout<<count<<endl;
}