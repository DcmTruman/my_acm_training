#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	int Case,N;
	cin>>Case;
	while(Case--)
	{
		int data[120][120]={0};
		int dp[120][120]={0};
		cin>>N;
		for(int i =0;i<N;i++){
			for(int j = 0;j<=i;j++){
				cin>>data[i][j];
			}
		}
		for( int i=0;i<N;i++)
		{
			dp[N-1][i] = data[N-1][i];
		}
		for(int i=N-1;i>=0;i--)
		{
			for(int j = 0;j<= i;j++)
			{
				dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+data[i][j];
			}
		}
		cout<<dp[0][0]<<endl;
	}
}