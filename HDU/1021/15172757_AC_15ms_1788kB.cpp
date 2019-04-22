#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long ll;
int main()
{


	ll a[1020];
	int aa[8] = {1,2,0,2,2,1,0,1};
	//a[0] = 7;
	//a[1] = 11;
	//for(int i = 2;i<1000;i++)a[i] = a[i-1]%3+a[i-2]%3;
	//for(int i = 0;i<100;i++)cout<<a[i]%3<<"\t";
	int n;
	while(cin>>n)
	{
		if(aa[n%8] == 0)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
	
	
}