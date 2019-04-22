#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
#include<math.h>
#include<vector>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck:"<<__LINE__<<endl;
using namespace std;

const int maxm = 1e6+20;
const int maxn = 1e5+20;


struct node{
	int x;
	int y;
	int id;
};
vector<node>V;
struct edge{
	node u;
	node v;
	double len;
};
vector<edge>E;

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

int main()
{
	int T;
	//cin>>T;
	while(cin>>n){
		V.clear();
		E.clear();
		//cin>>n;
		init();
		for(int i = 0;i<n;i++){
			int a,b;cin>>a>>b;
			V.push_back((node){a,b,i});
		}
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				edge temp;
				temp.u = V[i];
				temp.v = V[j];
				temp.len = sqrt((V[i].x-V[j].x)*(V[i].x-V[j].x)+(V[i].y-V[j].y)*(V[i].y-V[j].y));
				E.push_back(temp);
			}
		}
		cin>>m;
		for(int i = 0;i<m;i++){
			int a,b;cin>>a>>b;
			a -= 1;
			b -= 1;
			edge temp;
			temp.u = V[a];
			temp.v = V[b];
			temp.len = 0;
			E.push_back(temp);
		}
		sort(E.begin(),E.end(),cmp);
		double ans = 0;
		for(int i = 0;i<E.size();i++){
			node u = E[i].u;
			node v = E[i].v;
			double l = E[i].len;
			int x = find(u.id);
			int y = find(v.id);
			if(x!=y){
				fa[x] = y;
				ans += l;
			}
			else continue;
		}
		printf("%.2lf\n",ans);
	}
}