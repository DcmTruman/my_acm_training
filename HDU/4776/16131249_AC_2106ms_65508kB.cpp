#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
#define ll long long 
#define maxn 100020
using namespace std;

int tot = 0;
int head[maxn];
ll tmp;
struct node{
	ll val,num,k;
	bool operator <(const node &b) const{
		return val<b.val;
	}
	node(ll a,ll b,ll c):val(a),num(b),k(c){}
	node(){}
};
struct _edge{
	int v,next;
	ll val;
}edge[maxn<<1];

void addedge(int u,int v,ll x)
{
	edge[tot].v = v;
	edge[tot].next = head[u];
	edge[tot].val = x;
	head[u] = tot ++;
}

ll a[maxn];
priority_queue<node>Q;
void dfs(int now,int fa,ll x)
{
	a[now] = x;
	for(int i = head[now];~i;i = edge[i].next){
		if(edge[i].v == fa)continue;
		dfs(edge[i].v,now,edge[i].val^x);
	}
}

struct Trie{
	int nex[maxn*62][2];
	int cnt[maxn*62];
	int root;
	int sz;
	int newnode(){
		nex[sz][0] = nex[sz][1] = cnt[sz] = 0;
		return sz ++;
	}
	void init(){
		sz = 0;
		root = newnode();
	}
	void ins(ll x){
		int now = root;
		cnt[now] ++ ;
		for(int i = 61;i>=0;i--){
			if(x&(1ll<<i)){
				if(!nex[now][1])nex[now][1] = newnode();
				now = nex[now][1];
			}else{
				if(!nex[now][0])nex[now][0] = newnode();
				now = nex[now][0];
			}
			cnt[now] ++;
		}
	}
	ll query(ll x,int k){
		int now = root;
		ll res = 0;
		for(int i = 61;i>=0;i--){
			if(x&(1ll<<i)){
				if(nex[now][0] && cnt[nex[now][0]]>=k){
					res += (1ll<<i);
					now = nex[now][0];
				}else{
					if(nex[now][0])k -= cnt[nex[now][0]];
					now = nex[now][1];
				}
			}else{
				if(nex[now][1] && cnt[nex[now][1]]>=k){
					res += (1ll<<i);
					now = nex[now][1];
				}else{
					if(nex[now][1])k -= cnt[nex[now][1]];
					now = nex[now][0];
				}
			}
		}
		return res;
	}
}tri;

void init()
{
	tri.init();
	memset(head,-1,sizeof(head));
	tot = 0;
	while(!Q.empty())Q.pop();
}

int n,m;
int qus[maxn];
ll ans[maxn<<1];
int main()
{
	while(scanf("%d",&n)!=EOF&&n){
		init();
		for(int i = 1;i<n;i++){
			int u,v;
			ll w;
			scanf("%d%d%lld",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		dfs(1,1,0);
		//cout << "fuck"<<endl;
		for(int i = 1;i<=n;i++)tri.ins(a[i]);
		//for(int i = 1;i<=n;i++)ll x = tri.query(a[i],1),Q.push(({x,a[i],1});
		for(int i = 1;i<=n;i++){
			ll x = tri.query(a[i],1);
			//cout << "a[i] = "<<a[i]<<endl;
			Q.push(node(x,a[i],1));
		}
		scanf("%d",&m);
		int mx = 1;
		for(int i = 0;i<m;i++){
			scanf("%d",&qus[i]);	
			mx = max(mx,qus[i]);
		}
		for(int i = 1;i<=mx;i++){
			if(Q.empty())break;
			node u = Q.top();
			ans[i] = u.val;
			//cout <<i<<" "<<ans[i]<<endl;
			Q.pop();
			u.k++;
			if(u.k<n){
				u.val = tri.query(u.num,u.k);
				Q.push(u);
			}
		}
		for(int i = 0;i<m;i++){
			if(qus[i]>1ll*n*(n-1))printf("-1\n");
			else printf("%lld\n",ans[qus[i]]);
		}
	}
}