#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#define lson(x) ((x)<<1)
#define rson(x) ((x)<<1|1)

using namespace std;

const int maxn = 20020;
struct node{
	int l,r,kind,lazy;
	void update(int val){
		kind = val;
		lazy = val;
	}
}tree[maxn<<2];

void pushup(int x)
{
	if(tree[lson(x)].kind == -1 || tree[rson(x)].kind == -1){
		tree[x].kind = -1;
	}else if(tree[lson(x)].kind != tree[rson(x)].kind){
		tree[x].kind = -1;
	}else {
		tree[x].kind = tree[lson(x)].kind;
	}
}

void pushdown(int x)
{
	int la = tree[x].lazy;
	if(la){
		tree[lson(x)].update(la);
		tree[rson(x)].update(la);
		tree[x].lazy = 0;
	}
}

void build(int x,int l, int r)
{
	tree[x].l = l;tree[x].r = r;
	tree[x].lazy = 0;
	if(l == r){
		tree[x].kind = 0;
		return;
	}
	int mid = (l+r)/2;
	build(lson(x),l,mid);
	build(rson(x),mid+1,r);
	pushup(x);
	return;
} 

void update(int x,int l,int r,int val)
{
	int L = tree[x].l;
	int R = tree[x].r;
	if(l<=L&& R<=r ){
		//cout << "debug : " << L <<" "<<R<<" "<<val<<endl;
		tree[x].update(val);
		return ;
	}
	pushdown(x);
	int mid = (L+R)/2;
	if(l<=mid)update(lson(x),l,r,val);
	if(r>mid)update(rson(x),l,r,val);
	pushup(x);
	return ;
}

int query(int x,int pos)
{
	int L = tree[x].l;
	int R = tree[x].r;
	if(L == R){
		return tree[x].kind;		
	}
	pushdown(x);
	int mid = (L+R)/2;
	if(pos<=mid)return query(lson(x),pos);
	else if(pos>mid)return query(rson(x),pos );
	//pushup(x);
}

int temp[maxn];
int num[maxn];
int main()
{
	int n;
	while(cin >> n){
		memset(temp,0,sizeof(temp));
		memset(num,0,sizeof(num));
		
		build(1,1,8000);
		for(int i = 0;i<n;i++){
			int a,b,c;
			cin >> a >> b >> c;
			if(a>=b)continue;
			update(1,a+1,b,c+1);
		}
		//query(1,1,n+1);
		//int temp[maxn];
		//for(int i = 1;i<=n+1;i++){
			for(int i = 1;i<=8000;i++){
				temp[i] = query(1,i);
				if(temp[i] == -1)temp[i] = 0;
			}
		//}
		//int num[maxn]
		
		for(int i = 1;i<=8000;i++){
			if(temp[i]!=temp[i-1]){
				num[temp[i]]++;
			}
		}
		
		for(int i = 1;i<=8000;i++){
			if(num[i]){
				cout << i-1 << " " << num[i] << endl;
			}
		}
		cout << endl;
		
	}
}