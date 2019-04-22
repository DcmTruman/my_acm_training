#include<iostream>
#include<string.h>
#include<algorithm>
#define clr(x) memset(x,0,sizeof(x))

typedef long long ll;
using namespace std;

const int maxn = 1020;
ll w[maxn];//价值 
ll v[maxn];//体积 
ll f[maxn];
int main()
{
	int T;
	cin>>T;
	int V,N;
	while(T--)
	{
		clr(w);
		clr(v);
		clr(f);
		
		cin>>N>>V;
		for(int i = 1;i<=N;i++)
		{
			cin>>w[i];
		}
		for(int i = 1;i<=N;i++)
		{
			cin>>v[i];
		}
		for(int i = 1;i<=N;i++)
		{
			for(int j = V;j>=v[i];j--)
			{
				f[j] = max(f[j],f[j-v[i]]+w[i]);
			}
		}
		cout<<f[V]<<endl;
		
	}
}