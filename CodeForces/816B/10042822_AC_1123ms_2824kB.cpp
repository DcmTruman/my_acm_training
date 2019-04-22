#include<iostream>
using namespace std;
int ADD[200000+100];
int main()
{
	int m,n,q;
	cin>>m>>n>>q;
	for(int i = 0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		ADD[a]++;
		ADD[b+1]--;
	}
	for(int i = 1;i < 200100;i++)
	{
		ADD[i] +=ADD[i-1];
	}
	for(int i = 1;i < 200100;i++)
	{
		ADD[i] =ADD[i-1]+ (ADD[i]>=n);
	}
	for(int i =0;i<q;i++)
	{
		int a,b;
		cin>>a>>b;
		cout<<ADD[b]-ADD[a-1]<<endl;
	}
}