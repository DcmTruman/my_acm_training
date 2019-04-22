#include<iostream>
#include<string.h>
#include<string>
using namespace std;

const int maxn = 30;

int _map[maxn][maxn];
int n;
int ans = -1;

bool s[maxn];

void dfs(int a)
{
	if(a == n)
	{
		int sum = 0;
		for(int i = 0;i<n;i++)
		{
			if(s[i] == 1)
			{
				for(int j = 0;j<n;j++)
				{
					if(s[j]!=1)sum += _map[i][j];
				}
			}
		}
		ans = max(sum,ans);
		return;
	}
	for(int i = 0;i<2;i++)
	{
		s[a] = i;
		dfs(a+1);
	}
}

int main()
{
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			cin>>_map[i][j];
		}
	}
	
	dfs(0);
	cout<<ans<<endl;
	
}





