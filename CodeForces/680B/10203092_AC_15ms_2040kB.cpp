#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int ADD[120];
int main()
{
	int c,l,count = 0;
	cin>>c>>l;
	for(int i=1;i<=c;i++)
	{
		cin>>ADD[i];
	}
	if(ADD[l]==1)count++;
	int a=l-1,b=l+1;
	while(a>=1&&b<=c)
	{
		if(ADD[a]&&ADD[b])count +=2;
		a--;
		b++;
	}
	while(a>=1)
	{
		if(ADD[a])count++;
		a--;
	}
	while(b<=c)
	{
		if(ADD[b])count++;
		b++;
	}
	cout<<count<<endl;
}