#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
map<string,int>MM;
bool vis[1020];
int cnt;
vector<int>v[1020];
bool dfs(int now,int fa)
{
	int sz = v[now].size();
	for(int i = 0;i<sz;i++){
		int t = v[now][i];
		if(vis[t]){
			return false;
		}
		vis[t] = true;
		if(!dfs(t,now)){
			vis[t] = false;
			return false;
		}
		vis[t] = false;
	}
	return true;
}
bool isok()
{
	for(int i = 0;i<cnt;i++){
		vis[i] = true;
		if(!dfs(i,-1)){vis[i] = false;return false;}
		vis[i] = false;
	}
	return true;
}
int main()
{
	int n;
	while(cin >> n){
		MM.clear();
		cnt = 0;
		for(int i = 0;i<1020;i++)v[i].clear(),vis[i] = 0;
		int ans = -1;
		for(int i = 0;i<n;i++){
			string a,b;
			cin >> a >> b;
			if(!MM.count(a))MM[a] = cnt++;
			if(!MM.count(b))MM[b] = cnt++;
			v[MM[a]].push_back(MM[b]);
			if(ans == -1){
			if(!isok()){
				cout << a << " " << b << endl;
				ans = 0;
			}
			
			
		}}
		if(ans == -1)cout << "0" << endl;
	}
}

