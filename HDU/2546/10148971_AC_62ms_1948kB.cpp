#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while(N!=0)
	{
		int DP[1020] = {0,};
		int V[1020]={0,};
		int P;
		for(int i=0;i<N;i++)
		{
			cin>>V[i];
		}
		sort(V,V+N);
		cin>>P;
		int C = P-5;
		for(int i =0;i<N-1;i++)
		{
			for(int j =C;j>=V[i];j--)
			{
				DP[j] = max(DP[j],DP[j-V[i]]+V[i]);
			}
		}
		if(P>=5)cout<<P-DP[C]-V[N-1]<<endl;
		else cout<<P<<endl;
		cin>>N;
	}
	
}
