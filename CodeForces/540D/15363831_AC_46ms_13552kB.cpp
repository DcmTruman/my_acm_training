//pi = i*k/sum
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#define clr(x) memset(x,0,sizeof(x))
#define fuck cout<<"fuck"<<endl;

using namespace std;

const double eps = 1e-13 ;

double dp[120][120][120];

int r,s,p;

int main()
{
	while(cin>>r>>s>>p){
		clr(dp);
		dp[r][s][p] = 1.0;
		for(int i = r;i>=1;i--){
			for(int j = s;j>=1;j--){
				for(int k = p;k>=1;k--){
					double sum = i*j+j*k+k*i;
                    dp[i-1][j][k] += dp[i][j][k]*(i*k*1.0/sum);
                    dp[i][j-1][k] += dp[i][j][k]*(j*i*1.0/sum);
                    dp[i][j][k-1] += dp[i][j][k]*(j*k*1.0/sum);
				}
			}
		}
		double ans1,ans2,ans3;
		ans1 = ans2 = ans3 = 0;
		for(int i = 1;i<=100;i++){
			for(int j = 0;j<=100;j++){
				ans1 += dp[i][j][0];
				ans2 += dp[0][i][j];
				ans3 += dp[j][0][i]; 
			}
		}
		printf ( "%.12f %.12f %.12f\n" , ans1 , ans2 , ans3 );
		
	}
}
