#include<iostream>

using namespace std;

int main()
{
	long long a,b,c;
	while(cin>>a>>b>>c)
	{
		cout<<(a/c+((a%c == 0)?0:1))*(b/c+((b%c == 0)?0:1));
	}
}