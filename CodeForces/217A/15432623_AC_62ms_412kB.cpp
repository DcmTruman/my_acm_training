#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
#define clr(x,b) memset(x,(b),sizeof(x))

using namespace std;
const int maxn = 100020;
const int maxm = 100020;
struct node{
	int x;int y;
};
vector<node>a;
int fa[maxn];
int ans;
int n;
void init(){
	for(int i = 1;i<=n;i++){
		fa[i] = i;
	}
}

int find(int x){
	return (fa[x] == x)?x:fa[x] = find(fa[x]);
}

void join(int x,int y){
	int a = find(x);
	int b = find(y);
	if(a!=b){
		ans++;
		fa[a] = b;
	}
}




int main()
{
	while(cin>>n){
		init();
		a.clear();
		ans = 0;
		for(int i = 0;i<n;i++){
			int x,y;cin>>x>>y;
			a.push_back((node){x,y});
		}
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				if(a[i].x == a[j].x||a[i].y == a[j].y)join(i,j);
			}
		}
		cout<<n-ans-1<<endl;
	}
}