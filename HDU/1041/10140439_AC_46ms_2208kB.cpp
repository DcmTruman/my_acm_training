#include<iostream>
#include<stdio.h>
#include <algorithm>
#include<string.h>
#include<string>
using namespace std;
string D[1020];
string tempstr = "2";

string a;
int main()
{
	int N;
	D[0] = "0";
	D[1] = "0";
	D[2] = "1";
	D[3] = "1";
	D[4] = "3";
	string Tempstr="";
	int j;
		for(int i=5;i<1020;i++)
		{
			int temp;
			j=0;
			int c=0;
			for(int q = 0;q<tempstr.length();q++)
			{
				temp = 2 * (tempstr[q] - '0') + c;  
				c = temp / 10;  
				temp %= 10;      
				Tempstr += (temp + '0');  
			}
			if (c != 0)  
			{  
				Tempstr += (c + '0');  
			}
			tempstr = Tempstr;
			Tempstr="";
			int min = (tempstr.length()<D[i-2].length())?tempstr.length():D[i-2].length();
			int m=0;
			for( j=0;j<min;j++)
			{
				int temp1 =tempstr[j]-'0'+D[i-2][j]-'0'+m;
				m=temp1/10;
				temp1 %=10;
				D[i] += (temp1+'0');
			}
			if(min<tempstr.length())
			{
				for(;j<tempstr.length();j++)
				{
					int temp1 = (tempstr[j]-'0')+m;
					m= temp1/10;
					temp1 %=10;
					D[i] += (temp1+'0');
				}
			}
			 if(min<D[i-2].length())
			{
				for(;j<D[i-2].length();j++)
				{
					int temp1 = D[i-2][j]-'0'+m;
					m= temp1/10;
					temp1 %=10;
					D[i] += (temp1+'0');
				}
			}
			if(m!=0)
			{
				D[i] +=(m+'0');
			}
		}
	while(scanf("%d",&N)!=EOF)
	{
		
		for(int k =D[N].length()-1;k>=0;k--){
			cout<<D[N][k];
		}
		cout<<endl;
	}
}