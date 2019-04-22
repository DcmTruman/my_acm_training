#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
int main()
{
	cin>>N;
	int Num = N;
	while(N--)
	{
		int data[100000]={0};
		int num ;
		int flag = 0;
		int flag1=0;
		int flag2 = 0;
		cin>>num;
		for(int i=0;i<num;i++)
		{
			cin>>data[i];
		}
		int max = -1000;
		int sum = 0;
			for(int j =0;j<num;j++)
			{
				sum +=data[j];
				if(sum>max)
				{
					max = sum;
					flag1 = flag;
					flag2 = j;
				}
				if(sum < 0)
				{
					sum = 0;
					flag = j+1;
				}
			}
		
		
		cout<<"Case "<<Num-N<<":"<<endl;
		cout<<max<<" "<<flag1+1<<" "<<flag2+1<<endl;
		if(N!=0)cout<<endl;
		//cout<<Dp[num-1]<<endl;
		//for(int i=0;i<num;i++)cout<<Dp[i]<<" ";
		//cout<<endl;
	}
}
