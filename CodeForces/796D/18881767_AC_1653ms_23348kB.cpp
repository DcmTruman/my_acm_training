#include <stdio.h>
#include <map>
#include <utility>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <set>

using namespace std;
vector<int>st;


bool vis[300020];
int n,k,d;
struct node{
	int x;
	int dis;
};
struct edge{
	int u;
	int v;
	int id;
};
vector<edge>E;
vector<edge>V[300020];
bool ans[300020];
int main()
{
	cin >> n >> k >> d;
	for(int i = 0;i<k;i++){
		int a; cin >> a;
		st.push_back(a);
	}
	
	for(int i = 0;i<n-1;i++)
	{
		int x,y;
		cin >> x >> y;
		V[x].push_back(((edge){x,y,i+1}));
		V[y].push_back(((edge){y,x,i+1}));
	}
	queue<node>Q;
	for(int i = 0;i<k;i++){
		vis[st[i]] = true;
		Q.push((node){st[i] ,  0});
	}
	int at = 0;
	while(!Q.empty()){
		node t = Q.front();
		Q.pop();
		if(t.dis >= d)break;
		int sz = V[t.x].size();
		for(int i = 0;i<sz;i++)
		{
			int to = V[t.x][i].v;
			if(!vis[to]){
				vis[to] = true;
				Q.push((node){to , t.dis + 1});
				ans[V[t.x][i].id] = true;
				at++;
			}
		}
	}
	cout << n - 1 - at << endl;
	for(int i = 1;i<n;i++){
		if(!ans[i]){
			cout << i << " ";
		}
	}
}
