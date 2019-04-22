#include <iostream>
#include <string>
#include <string.h>
#define lson(x) ((x)<<1)
#define rson(x) ((x)<<1|1)

using namespace std;
const int maxn = 100020;
int a[maxn];
struct {
	int l,r,mn,mx;
}tree[maxn<<2];

void pushup(int x)
{
	tree[x].mn = min(tree[lson(x)].mn,tree[rson(x)].mn);
	tree[x].mx = max(tree[lson(x)].mx,tree[rson(x)].mx);
}

void build(int x,int l,int r)
{
	tree[x].l = l;
	tree[x].r = r;
	if(l == r){
		tree[x].mn = tree[x].mx = a[l];
		return;
	}
	int mid = (l + r)/2;
	build(lson(x),l,mid);
	build(rson(x),mid+1,r);
	pushup(x);
	return;
}

int query1(int x,int l,int r)
{
	int L = tree[x].l;
	int R = tree[x].r;
	if(l<=L&&R<=r){
		return tree[x].mn;
	}
	int mid = (L+R)/2;
	int ans = 0x3f3f3f3f;
	if(l<=mid)ans = min(ans,query1(lson(x),l,r));
	if(r>mid)ans = min(ans,query1(rson(x),l,r));
	return ans;
}
int query2(int x,int l,int r)
{
	int L = tree[x].l;
	int R = tree[x].r;
	if(l<=L&&R<=r){
		return tree[x].mx;
	}
	int mid = (L+R)/2;
	int ans = 0;
	if(l<=mid)ans = max(ans,query2(lson(x),l,r));
	if(r>mid)ans = max(ans,query2(rson(x),l,r));
	return ans;
}  

int main()
{
	int n,q;
	while(~scanf("%d%d",&n,&q)){
		
	
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	while(q--){
		int aa,bb;
		//cin >> aa >> bb;
		scanf("%d%d",&aa,&bb);
		printf("%d\n",query2(1,aa,bb)-query1(1,aa,bb));
		//cout << query2(1,aa,bb)-query1(1,aa,bb)<<endl;
	}
}
}