#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>

using namespace std;


bool visit[10];
vector<int>V;
int ss;

void dfs(int w,int a)
{
	if(w == 0)
	{
		V.push_back(a);
		return;
	}
	
	for(int i = 0;i<10;i++)
	{
		if(ss == w&&i == 0)continue;
		if(!visit[i])
		{
			visit[i] = true;
			int t = 10*a+i;
			dfs(w-1,t);
			visit[i] = false;
		}
	}
}
int main()
{
	int n = 0;
	for(int i = 1;i<=8;i++)
	{
		ss = i;
		dfs(i,n);
	}
	sort(V.begin(),V.end());
	//for(int i = 0;i<26;i++)cout<<V[i]<<" ";
	//cout<<V.size()<<endl;
	int T;
	while(cin>>T&&T)cout<<V[T-1]<<endl;

return 0;
}