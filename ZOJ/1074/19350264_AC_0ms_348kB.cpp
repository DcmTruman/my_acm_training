#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 120;
int aa[maxn][maxn];
int b[maxn];
int n,m;
int main()
{
	memset(aa,0,sizeof(aa));
	scanf("%d",&n);
	m = n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			scanf("%d",&aa[i][j]);
		}
	}	
	int mx = -INF;
	for(int i = 1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j = i;j<=n;j++){
			int sum = 0;
			for(int k = 1;k<=n;k++){
				b[k] += aa[j][k];
				sum = (sum < 0)?0:sum;
				sum += b[k];
				mx = max(mx,sum);
			}
		}
	}
	printf("%d\n" , mx);
}
