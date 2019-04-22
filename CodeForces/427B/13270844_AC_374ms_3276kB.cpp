#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstring>
using namespace std;


typedef long long ll;
ll N,T,C;

int main()
{
	int pos = 0;
	int count = 0;
	int ans = 0;
	while(cin>>N>>T>>C)
	{
		pos = -1;
		count = 0;
		ans = 0;
		int max = -1;
		int a;
		for(int i = 0;i<N;i++)
		{
			cin>>a;
			if(a<=T&&i>pos)
			{
				if(count!=C)count++;
				//cout<<a<<","<<T<<","<<pos<<","<<count<<endl;
				if(count == C)ans++;
			}
			else if(a>T)
			{
				pos = i;
				count = 0;
			}
		}
		cout<<ans<<endl;
	}

}