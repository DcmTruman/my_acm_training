#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <algorithm>

#define ll long long
using namespace std;

vector<ll>v;
struct node{
	ll val;
	ll cnt;
	int len;
};
void bfs()
{
	queue<node>Q;
	node st;
	for(int i = 1;i<10;i++)
	{
		st.val = (ll)i;
		st.cnt = 1;
		st.len = 1;
		Q.push(st);
	}
	while(!Q.empty())
	{
		node t = Q.front();
		Q.pop();
		if(t.len > 19)return;
		v.push_back(t.val);
		st.val = t.val * 10;
		st.cnt = t.cnt;
		st.len = t.len + 1;
		Q.push(st);
		for(int i = 1;i<=9;i++){
			st.val = t.val * 10 + i;
			st.cnt = t.cnt + 1;
			st.len = t.len + 1;
			if(st.cnt <= 3)Q.push(st);
		}
	}
}
void init()
{
	bfs();
	sort(v.begin(),v.end());
}
int main()
{
	int T;cin >> T;
	init();
	while(T--)
	{
		ll l,r;cin >> l >> r;
		l = lower_bound(v.begin(),v.end(),l) - v.begin();
		r = upper_bound(v.begin(),v.end(),r) - v.begin();
		cout << r - l << endl;
	}
return 0;
}
