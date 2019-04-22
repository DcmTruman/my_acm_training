#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck:"<<__LINE__<<endl;
using namespace std;

const int maxm = 1e6+20;
const int maxn = 1e5+20;
struct edge{
	int u;
	int v;
	int len;
}E[maxm];

bool cmp(edge a,edge b){
	return a.len<b.len;
}
bool visit[maxm];
int fa[maxn];
int n,m;
void init(){
	for(int i = 0;i<=n;i++)fa[i] = i;
}
int find(int x){
	return (fa[x] == x)?x:fa[x] = find(fa[x]);
}

void join(int a,int b){
	int x = find(a);
	int y = find(b);
	if(x!=y)fa[x] = y;
}

int main()
{
	cin>>n>>m;
	clr(visit,0);
	init();
	for(int i = 0;i<m;i++){
		cin>>E[i].u>>E[i].v>>E[i].len;
	}
	sort(E,E+m,cmp);
	int ans = 0;
	for(int i = 0;i<m;i++){
		int u = E[i].u;
		int v = E[i].v;
		int l = E[i].len;
		int x = find(u);
		int y = find(v);
		if(x!=y){
			fa[x] = y;
			ans += l;
		}
		else continue;
	}
	cout<<ans<<endl;
}