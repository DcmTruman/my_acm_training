//dp[i][j] 公主抓时，i只白猫j只黑猫时，赢得概率 
//dp[i][j] = i/(i+j)
//dp[i][j] += (j/(i+j))*((j-1)/(i+j-1))*(i/(i+j-2))*dp[i-1][j-2]//王黑，龙黑，逃白 
//dp[i][j] += (j/(i+j))*((j-1)/(i+j-1))*((j-2)/(i+j-2))*dp[i][j-3]//王黑，龙黑，逃黑 
//dp[i][0] = 1;
//dp[0][j] = 0; 


#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define clr(x) memset(x,0,sizeof(x));

const int maxn = 1020;

int w,b;
double dp[maxn][maxn];



 

int main()
{
	while(cin>>w>>b){
		clr(dp);
		for(int i = 1;i<=w;i++)dp[i][0] = 1;
		for(int i = 0;i<=b;i++)dp[0][i] = 0;
		for(int i = 1;i<=w;i++){
			for(int j = 1;j<=b;j++){
				dp[i][j]=i*1.0/(i+j);
				if(j>=2)dp[i][j]+=j*1.0/(i+j) * (j-1)*1.0/(i+j-1) * i*1.0/(i+j-2) * dp[i-1][j-2];
				if(j>=3)dp[i][j]+=j*1.0/(i+j) * (j-1)*1.0/(i+j-1) * (j-2)*1.0/(i+j-2) * dp[i][j-3];
			}
		} 
		printf("%.9f\n",dp[w][b]);
	}
}