#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>n;
		double sum = 0;
		while(n>=1)
		{
			sum += log10(n);
			n--;
		}
		cout<<(int)sum+1<<endl;
	} 
}