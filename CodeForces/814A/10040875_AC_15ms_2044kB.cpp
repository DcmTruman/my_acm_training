#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int m,n;
	int flag =0;
	cin>>m>>n;
	vector<int>M;
	vector<int>N;
	for(int i=0;i<m;i++)
	{
		int a;
		cin>>a;
		M.push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		N.push_back(a);
	}
	sort(N.begin(),N.end(),cmp);
	for(int i=0;i<m;i++)
	{
		if(M[i]==0)
		{
			M[i] = N[flag++];
		}
	}
	vector<int>temp = M;
	sort(temp.begin(),temp.end());
	if(temp==M)cout<<"No";
	else cout<<"Yes";
}