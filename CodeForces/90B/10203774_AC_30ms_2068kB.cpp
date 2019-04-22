#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string ADD[120];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>ADD[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int flag=0;
			for(int k=0;k<m;k++)
			{
				if(ADD[i][j]==ADD[i][k]&&j!=k)
				{
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				for(int k=0;k<n;k++)
			{
				if(ADD[i][j]==ADD[k][j]&&k!=i)
				{
					flag=1;
					break;
				}
			}
			}
			if(!flag)cout<<ADD[i][j];
		}
	}
}