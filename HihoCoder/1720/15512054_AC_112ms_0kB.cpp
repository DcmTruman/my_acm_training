#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck:"<<__LINE__<<____endl
#define MOD (ll)(1e9+7)

using namespace std;

const int maxn = 1000020;
int num[10];
int main()
{
	int m,n;
	while(cin>>n>>m){
		clr(num,0);
		int t = n;
		for(int i = 0;i<maxn;i++){
			t = t*10;
			int x = t/m;
			num[x]++;
			t%=m;
			if(t == 0)break;
		}
		for(int i = 0;i<10;i++){
			if(num[i]!=0)cout<<i;
		}
		cout<<endl;
		
	}
}
