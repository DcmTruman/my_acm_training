#include<iostream>


int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;	
} 

int main()
{
	int a,b,c;
	while(std::cin>>a>>b>>c&&a+b+c)
	{
		a /= gcd(b,c);
		if(a&1)std::cout<<"NO"<<std::endl;
		else std::cout<<a-1<<std::endl;
	}
	return 0;
}