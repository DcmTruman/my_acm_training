#include <iostream>
#include<algorithm>
using namespace std;

const int maxn = 10000020;

int N[maxn];

int main()
{
	N[1] = 1;
	int p1 = 1;
	int p2 = 1;
	for(int i = 2;i<=10000000;i++)
	{
		N[i] = min(2*N[p1]+1,3*N[p2]+1);
		if(N[i] == 2*N[p1]+1)p1++;
		if(N[i] == 3*N[p2]+1) p2++;
	}
	int n;
	while(cin>>n)
	{
		cout<<N[n]<<endl;
	}
}
