#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <queue>
#define ll long long
using namespace std;

#define INF 0x3f3f3f3f;

const ll maxn = 2e5+20;
int m,n;
int fa[maxn];
void init(int n){
	for(int i = 0;i<=n;i++)fa[i] = i;
}

int find(int x){
	return (fa[x] == x)?x:fa[x] = find(fa[x]);
}

void merge(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx != fy)fa[fx] = fy;
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d" , &n , &m);
		init(n);
		int ans = 0;
		while(m--){
			int u,v;scanf("%d%d",&u,&v);
			merge(u,v);
		}
		for(int i = 1;i<=n;i++){
			if(i == find(i))ans ++;
		}
		printf("%d\n",ans);
		
	}
}
