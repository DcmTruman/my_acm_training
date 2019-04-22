#include<iostream>
#include<string>
#include<algorithm>
using namespace std ;
int main()
{
	int k2,k3,k5,k6,sum=0;
	cin>>k2>>k3>>k5>>k6;
	int k256 =min(k2,k5);
	k256 = min(k256,k6);
	sum +=k256*256;
	k2 -=k256;
	int k32 = min(k2,k3);
	sum += k32*32;
	cout<<sum<<endl;
}