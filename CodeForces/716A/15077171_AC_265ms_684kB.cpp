#include<iostream>
using namespace std;

int main()
{
	int n,k;
	int ant;
	int num[100005];
	cin>>n>>k;
	for (int i = 1 ; i <= n ; i++)
	{
		cin>>num[i];
	}
	ant = 1;
	for (int i = 2 ; i <= n ; i++)
	{
	if (num[i] - num[i-1] <= k)
	{
		ant++;
	}
	else
	{
		ant = 1;
	}
	}
	cout<<ant<<endl;
	return 0;
}