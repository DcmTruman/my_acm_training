#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#define clr(x,b) memset(x,(b),sizeof(x))

using namespace std;
const int maxn = 100020;
const int maxm = 100020;
int m,n;
int fa[maxn];
int du[maxn];
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
	if(a!=b)fa[a] = b;
}

int main()
{
	while(cin>>n>>m){
		init();
		clr(du,0);
		for(int i = 0;i<m;i++){
			int a,b;cin>>a>>b;
			join(a,b);
			//cout<<a<<b;
			du[a]++;
			du[b]++;
		}
		bool flag = true;
		for(int i = 1;i<=n;i++){
			//cout<<find(i)<<endl;
			if(find(i)!=find(1)){
				flag = false;
				//cout<<"fuck"<<endl;
				break;
			}
		}
		for(int i = 1;i<=n;i++){
			if(du[i]&1){
				flag = false;
				break;
			}
		}
		if(flag)cout<<"1"<<endl;
		else cout<<"0"<<endl;
	}
}