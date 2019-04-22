#include<iostream>
#include<string.h>
#include<algorithm>

#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
using namespace std;




int C[30];
int G[30];
int dp[30][15000];

int main()
{
	int c,g;
	cin>>c>>g;
	//cout<<c<<g;
	for(int i = 1;i<=c;i++)
	{
		cin>>C[i];
	}
	for(int i = 1;i<=g;i++)
	{
		//cout<<"fuck"<<endl;
		cin>>G[i];
	}
	
	clr(dp);
	
	dp[0][6000] = 1;
	for(int i = 1;i<=g;i++)
	{
		for(int j = 0;j<=12000;j++)
		{
			if(dp[i-1][j])
			{
				for(int k = 1;k<=c;k++)
				{
					dp[i][j+C[k]*G[i]] += dp[i-1][j];	
				}	
			}	
		}
	}
	cout<<dp[g][6000]<<endl;
}



