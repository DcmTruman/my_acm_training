#include<iostream>
#include<queue>

using namespace std;



long long add[201];

int Bfs(long long a)
{
	queue<long long>Q;
	Q.push(1);
	while(!Q.empty())
	{
		long long temp = Q.front();
		Q.pop();
		if(temp%a == 0)
		{
			add[a] = temp;
			return 1;
		}
		long long t1 = temp*10;
		long long t2 = temp*10+1;
		Q.push(t1);
		Q.push(t2);
	}
	return 0;
}
int main()
{
	long long a;
	for(long long i = 1;i<=200;i++)
	{
		Bfs(i);
	}
	while(cin>>a&&a)
	{
		cout<<add[a]<<endl;
	}
} 