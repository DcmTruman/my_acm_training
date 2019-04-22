#include <iostream>
#include <queue>
#include <string.h>
#include <cstring>
#define ll long long 
using namespace std;

struct node{
	int sta;
	int ww;
	ll num;	
};

ll ans[1000020];
void init()
{
	int cnt = 1;
	node temp;
	queue<node>Q;
	for(ll i = 1;i<=9;i++){
		temp.sta = (1<<i);
		temp.ww = 1;
		temp.num = i;
		Q.push(temp);	
	}
	while(!Q.empty())
	{
		if(cnt > 1000010)break;
		node t = Q.front();
		ans[cnt ++] = t.num;
		Q.pop();
		for(int i = 0;i<=9;i++)
		{
			if((t.sta & (1 << i)) == 0)
			{
				temp.ww = t.ww + 1;
				temp.sta = t.sta | (1 << i);
				temp.num = t.num * 10 + i;
				Q.push(temp);
			}
		}
	}
}
int main()
{
	init();
	int n;
	while(cin >> n && n){
		cout << ans[n] << endl;
	}
}
