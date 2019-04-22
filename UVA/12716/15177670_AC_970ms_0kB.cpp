#include<iostream>
#include<stdio.h>

using namespace std;


int const maxn = 30000005;
int ans[maxn];
 

 
int main()
{
	for(int c = 1;c < maxn; c++) 
	{
		for(int a = c + c; a < maxn; a += c){
			if((a ^ (a - c)) == c)ans[a] ++;
		}
		ans[c] += ans[c - 1];
	}
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int n;
		scanf("%d", &n);
		printf("Case %d: %d\n", t, ans[n]);
	}
}