#include<iostream>
using namespace std;
#include<vector>
int N,m,catnum = 0,ans = 0;
vector<vector<int>>V;
bool Cats[200020];
bool Visit[200020];

void dfs(int now)
{
	Visit[now]=true;
	int tempcat = catnum;
	if(Cats[now])
	{
		catnum++;
		if(catnum>m)
		{
			catnum--;
			return;
		}
	}
	else
	{
		catnum = 0;
	}
	//if(!V[now].size())
	//{
	//	catnum = tempcat;
	//	ans++;
	//	return;
	//}
	int flag=1;
	for(int i=0;i<V[now].size();i++)
	{
		if(!Visit[V[now][i]])flag=0;
	}
	if(flag == 1)
	{
		catnum = tempcat;
		ans++;
		return;
	}
	for(int i=0;i<V[now].size();i++)
	{
		if(!Visit[V[now][i]])
		{
		dfs(V[now][i]);
		}
	}
	catnum = tempcat;
	return;
}
int main()
{
	cin>>N>>m;
	for(int i=1;i<=N;i++)
	{
		cin>>Cats[i];
	}
	V.resize(N+5);
	for(int i=1;i<=N-1;i++)
	{
		int a,b;
		cin>>a>>b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	dfs(1);
	cout<<ans<<endl;
}