#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int Map[8][8];
int temp[8]={0,};
int Count,n,k;
void Try(int a,int b)
{
	for(int i =0;i<n;i++)
	{
		if(Map[a][i]==1&&temp[i]==0)
		{
			if(b==1)
			{
				Count++;
			}
			else
			{
				temp[i] = 1;
				for(int j = a+1;j<n-b+2;j++)
				{
					Try(j,b-1);
				}
				temp[i] = 0;
			}
		}
	}
}
 int main()
 {
	 cin>>n>>k;
	 while(n>=0&&k>=0)
	 {
	Count = 0;
	 for(int i = 0;i<n;i++)
	 {
		 for(int j = 0;j<n;j++)
		 {
			char s;
			cin>>s;
			if(s == '#')
			{
				Map[i][j] = 1;
			}
			else
			{
				Map[i][j] = 0;
			}
		 }
	 }
	 for(int i = 0;i<n;i++)
	 {
		 Try(i,k);
	 }
	 cout<<Count<<endl;
	 cin>>n>>k;
   }
 }