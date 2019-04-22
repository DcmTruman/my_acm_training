#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstring>
#include<vector>
using namespace std;

int main()
{
	vector<int>V;
	int N;
	cin>>N;
	for(int i = 0;i<2*N;i++)
	{
		int a;
		cin>>a;
		V.push_back(a);
	}
	int min = 0x3f3f3f3f;
	int ans = 0;
	sort(V.begin(),V.end());
	for(int i = 0;i<N;i++)
	{
		ans += abs(V[2*i]-V[2*i+1]);
	}
	if(ans<min)min = ans;
	for(int i = 0;i<2*N;i++)
	{
		for(int j = i+1;j<2*N;j++)
		{
			int tans = 0;
			if(i == j)continue;
			vector<int>temp = V;
			vector<int>::iterator   ii   =   temp.begin()+i;
			vector<int>::iterator   jj   =   temp.begin()+j;
			temp.erase(ii);
			temp.erase(jj-1);
			
			for(int k = 0;k<N-1;k++)
			{
				tans += abs(temp[2*k]-temp[2*k+1]);
			}
			if(tans<min)min = tans;
			
		}
	}
	cout<<min<<endl;
}