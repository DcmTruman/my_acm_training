//优先考虑 
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#define clr(x) memset(x,0,sizeof(x))
#define fuck cout<<"fuck"<<endl;

using namespace std;

//dp[i][q] 

struct node{
	int p,q,v;
};
bool cmp(node a,node b){
	return a.q-a.p<b.q-b.p;
}
node aa[520];

int dp[5020];
int m,n;

int main()
{
	while(cin>>n>>m){
		for(int i = 0;i<n;i++){
			cin>>aa[i].p>>aa[i].q>>aa[i].v;
		}
		sort(aa,aa+n,cmp);
		clr(dp);
		for(int i = 0;i<n;i++){
			for(int j = m;j>=aa[i].q;j--){
				dp[j] = max(dp[j],dp[j-aa[i].p]+aa[i].v);
			}
		}
		//for(int i = 0;i<=m;i++)cout<<dp[i]<<" ";
		cout<<dp[m]<<endl;
	}
	return 0;
}
