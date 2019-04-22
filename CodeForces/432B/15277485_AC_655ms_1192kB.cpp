#include<iostream>
#include<string.h>
#include<string>
using namespace std;

const int maxn = 1e5+20;


int n;

int home[maxn];
int away[maxn];
int num[maxn];

int main()
{
	cin>>n;
	for(int i =1;i<=n;i++)
	{
		cin>>home[i]>>away[i];
		num[home[i]]++;
	}

	for(int i = 1;i<=n;i++)
	{
		cout<<n-1+num[away[i]]<<" "<<n-1-num[away[i]]<<endl;
	}
	
	
}





