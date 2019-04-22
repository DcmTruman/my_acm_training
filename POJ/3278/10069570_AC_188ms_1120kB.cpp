#include<iostream>
#include<queue>
using namespace std;
typedef struct _E{
	int n;
	int min;
}E;
bool ADD[200100] = {false};
int main()
{
	long long N,K;
	int flag = 0;
	int ans;
	cin>>N>>K;
	queue<E>Q;
	E t = {N,0};
	Q.push(t);
	while(!Q.empty())
	{
		E a = Q.front();
		Q.pop();
		if(a.n!=K)
		{
			if(a.n<K)
			{
				if(!ADD[a.n*2]){
					E temp1 = {a.n*2,a.min+1};
					Q.push(temp1);
					ADD[a.n*2] = true;
				}
				if(!ADD[a.n+1]){
					E temp2 = {a.n+1,a.min+1};
					Q.push(temp2);
					ADD[a.n+1] = true;
				}
				if(!ADD[a.n-1]){
					E temp3 = {a.n-1,a.min+1};
					Q.push(temp3);
					ADD[a.n-1] = true;
				}
			}
			else
			{
				if(!ADD[a.n-1]){
					E temp3 = {a.n-1,a.min+1};
					Q.push(temp3);
					ADD[a.n-1] = true;
				}
			}
		}
		else
		{
			ans = a.min;
			break;
		}
		
	}
	cout<<ans<<endl;
}