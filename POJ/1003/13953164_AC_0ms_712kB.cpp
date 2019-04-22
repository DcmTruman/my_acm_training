#include<iostream>

using namespace std;

int main()
{
	double a;
	cin>>a;
	while(a-0>=0.01)
	{
		double len = 0.5;
		int n = 1;
		while(len<a)
		{
			n++;
			len = len + double(1)/(n+1);
		}
		cout<<n<<" card(s)"<<endl;
		cin>>a;
	}
}