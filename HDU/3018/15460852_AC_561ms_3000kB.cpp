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
int fa[maxn];
int num[maxn];
int ji[maxn];
int du[maxn];
int m,n,ans;
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
	while(cin>>n>>m){
		init();
		clr(num,0);
		clr(ji,0);
		clr(du,0);
		for(int i = 0;i<m;i++){
			int a,b;cin>>a>>b;
			du[a]++;
			du[b]++;
			join(a,b);
		}
		for(int i = 1;i<=n;i++){
			num[find(i)]++;
			if(du[i]&1)ji[find(i)]++;
		}
		ans = 0;
		for(int i = 1;i<=n;i++){
			if(num[i]<=1)continue;
			else if(ji[i] == 0)ans ++;
			else if(ji[i]>0)ans += ji[i]/2;
		}
		cout<<ans<<endl;
	}
    return 0 ;
}