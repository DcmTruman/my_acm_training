#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck() cout<<"fuck:"<<__LINE__<<endl;
using namespace std;
typedef long long ll;

const int maxn = 50020;
int n;
int main()
{
	cin>>n;
	ll a,c,d;
	ll cost = 0;
	priority_queue<ll,vector<ll>,greater<ll> >q;
	for(int i = 0;i<n;i++)cin>>a,q.push(a);
	while(!q.empty()){
		d = 0;
		c = q.top(),q.pop();
		if(!q.empty()){
			d = q.top(),q.pop();
			cost += c+d;
			q.push(c+d);
		}
	}
	cout<<cost<<endl;
} 