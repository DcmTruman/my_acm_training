#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
#include<string>
#define clr(x,b) memset(x,(b),sizeof(x))

using namespace std;
const int maxn = 100020;
const int maxm = 200020;
typedef long long ll;
ll num[maxn],tail[maxn];
ll ans = 0;
int m,n;
struct edge{
	int u;
	int v;
};
edge E[maxm];

bool cmp(edge a,edge b){
	if(a.u == b.u)return a.v<b.v;
	return a.u<b.u;
}
int main()
{
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int a,b;cin>>a>>b;
		E[i].u = min(a,b);E[i].v = max(a,b);
		num[a]++;
		num[b]++;
	}
	sort(E+1,E+1+m,cmp);
	for(int i = 1;i<=m;i++){
		tail[E[i].v] = max(tail[E[i].v],tail[E[i].u]+1);
	}
	for(int i =1;i<=n;i++){
		ans = max(ans,(tail[i]+1)*num[i]);
	}
	cout<<ans<<endl;
}