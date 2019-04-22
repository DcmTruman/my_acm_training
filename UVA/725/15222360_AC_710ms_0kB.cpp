#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

bool check(int a,int b)
{
	int n = log10(a)+1;
	int n2 = log10(b)+1;
	if(n<4||n>5)return false;
	vector<int>aa;
	if(n==4)aa.push_back(0);
	if(n2==4)aa.push_back(0);
	
	for(int i = 0;i<n;i++)
	{
		aa.push_back(a%10);
		a/=10;
	}
	for(int i = 0;i<n2;i++)
	{
		aa.push_back(b%10);
		b/=10;
	}
	for(int i = 0;i<aa.size()-1;i++)
	{
		for(int j = i+1;j<aa.size();j++)
		{
			if(aa[i] == aa[j])return false;
		}
	}
	return true;
}

int main()
{
	int N;
	int fk = 0;
	while(cin>>N&&N)
	{
		if(fk++>0)cout<<endl;
		bool flag = false;
		for(int i = 1000;i<99999;i++)
		{
			if(check(N*i,i))
			{
				flag = true;
				printf("%05d / %05d = %d\n",N*i,i,N);
			}
		}
		if(!flag)cout<<"There are no solutions for "<<N<<".\n";
	}
}