#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstring>
using namespace std;


int add[50][50];
int M,N;
int main()
{
	while(cin>>N>>M)
	{
		for(int i = 0;i<N;i++)
		{
			for(int j = 0;j<M;j++)
			{
				cin>>add[i][j];
			}
		}
		int flag = 0;
		for(int i = 0;i<M;i++)
		{
			for(int j = 0;j<M;j++)
			{
				flag = 0;
				for(int k = 0;k<N;k++)
				{
					swap(add[k][i],add[k][j]);
				}
				int count = 0;
				for(int q = 0;q<N;q++)
				{
					count = 0;
					for(int o = 0;o<M;o++)
					{
						if(add[q][o]!=o+1){count++;}
					}
					if(count!=0&&count!=2)
					{
						//cout<<i<<","<<j<<","<<count<<endl;
						flag = 1;
						break;
					}
					
				}
				for(int k = 0;k<N;k++)
				{
					swap(add[k][i],add[k][j]);
				}
				if(flag == 0)
				{
					//cout<<"YES"<<endl;
					break;
					//return 0;
				}
			}
			if(flag == 0)break;
		}
		if(flag == 0)cout<<"YES"<<endl;
		else{
cout<<"NO"<<endl;
		}
		
	}

}