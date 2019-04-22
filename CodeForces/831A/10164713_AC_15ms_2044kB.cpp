#include<iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	bool in =true;
	bool de = false;
	bool co = false;
	bool un = true;
	int a;
	cin>>a;
	for(int i=1;i<N;i++)
	{
		int b;
		cin>>b;
		if(b>a)
		{
			if(de||co){un = false;break;}
			else if(in){in = true;de=false;co=false;un=true;}
			a=b;
		}
		else if(b==a)
		{
			if(in){de=false;in=false;co =true;un =true;}
			else if(co){de=false;in=false;co =true;un =true;}
			else if(de){un=false;break;}
			a=b;
		}
		else if(b<a)
		{
			if(co){de=true;in=false;co=false;}
			else if(in){de=true;in=false;co=false;}
			a=b;
		}
	}
	if(un)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}