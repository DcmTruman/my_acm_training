#include<iostream>
using namespace std;
bool Seat[200100];
bool Taken[200100];
int main()
{
	int N,one,two,c=0,ans=0;
	cin>>N>>one>>two;
	for(int i=0;i<N;i++)
	{
		int a;
		cin>>a;
		if(a==1)
		{
			if(one>0)one--;
			else if(two>0)
			{
				two--;
				c++;
			}
			else if(c>0)
			{
				c--;
			}
			else ans++;
		}
		else if(a==2)
		{
			if(two>0)two--;
			else ans += 2;
		}
	}
	cout<<ans<<endl;
}