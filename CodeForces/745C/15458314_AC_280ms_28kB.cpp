#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
#include<string>
#define clr(x,b) memset(x,(b),sizeof(x))

using namespace std;
const int maxn = 1020;
int fa[maxn],num[maxn];
int ca[maxn];
int m,n,k;

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
	while(cin>>n>>m>>k){
		init();
		clr(num,0);
		for(int i = 0;i<k;i++)cin>>ca[i];
		for(int i = 0;i<m;i++){
			int a,b;cin>>a>>b;
			join(a,b);
		}
		for(int i = 1;i<=n;i++)num[find(i)]++;
		int mx = 0;
		int ans = 0;
		int node = n;
		for(int i = 0;i<k;i++){
			num[ca[i]] = num[find(ca[i])];
			mx = max(num[ca[i]],mx);
			node -= num[ca[i]];
			//cout<<ans<<endl;
			ans += (num[ca[i]]-1)*(num[ca[i]])/2;
		}
		ans += (node+mx)*(node+mx-1)/2;
		ans -= mx*(mx-1)/2+m;
		cout<<ans<<endl;
	}
	return 0;
}