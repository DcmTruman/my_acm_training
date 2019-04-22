#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
const int maxn = 100020;
int id[maxn];
int T,n;
struct node{
	int l;
	int r;
	int id;
}seg[maxn];

bool cmp(node a,node b)
{
	return a.l < b.l;
}

bool jiao(int a,int b,node c)
{
	if(c.l <= b && c.l >= a)return true;
	if(c.r >= a && c.r <= b)return true;
	return false;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 0;i<n;i++){
			id[i] = 2;
			int a,b;
			cin >> a >> b;
			seg[i].l = a;
			seg[i].r = b;
			seg[i].id = i;
		}
		sort(seg,seg+n,cmp);
		int nowa = seg[0].l;
		int nowb = seg[0].r;
		int cnt = 1;
		id[seg[0].id] = 1;
		for(int i = 1;i<n;i++){
			if(jiao(nowa,nowb,seg[i])){
				id[seg[i].id] = 1;
				cnt ++;
				nowa = min(nowa,seg[i].l);
				nowb = max(nowb,seg[i].r);
			}
		}
		if(cnt == n){
			cout << -1 << endl;
		}
		else{
			for(int i = 0;i<n;i++){
				cout << id[i] << " ";
			}
			cout << endl;
		}
	}
}
