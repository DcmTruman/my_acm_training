#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#define clr(x,b) memset(x,(b),sizeof(x))

using namespace std;
const int maxn = 100020;
const int maxm = 100020;

struct node{
	int to;
	int w;
};
vector<node>V[maxn];
vector<int>fl;
bool isfl[maxn];
int n,m,k;

int main()
{
	cin>>n>>m>>k;
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		
		V[a].push_back((node){b,c});
		V[b].push_back((node){a,c});
	}
	for(int i = 0;i<k;i++){
		int a;cin>>a;
		fl.push_back(a);
		isfl[a] = true;
	}
	int ans = 0x3f3f3f3f;
	for(int i = 1;i<=n;i++){
		if(isfl[i]){
			for(int j = 0;j<V[i].size();j++){
				int t = V[i][j].to;
				int tl = V[i][j].w;
				if(!isfl[t]){
					ans = min(ans,tl);
				}
			}
		}
	}
	if(ans == 0x3f3f3f3f)cout<<"-1"<<endl;
	else cout<<ans<<endl;
}