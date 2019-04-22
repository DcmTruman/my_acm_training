#include<iostream>
using namespace std;

int main()
{
	long double n,u,d,f;
	cin>>n;
	while(n)
	{
		cin>>u>>d>>f;
		int day = 0;
		long double T = f*0.01*u;
		long double h=0;
		while(1)
		{
			day++;
			h += u;
			if(h>n){cout<<"success on day "<<day<<endl;break;}
			h -=d;
			if(h<0){cout<<"failure on day "<<day<<endl;break;}
			u-=T;
			if(u<0)u=0;
		}
		cin>>n;
	}
}