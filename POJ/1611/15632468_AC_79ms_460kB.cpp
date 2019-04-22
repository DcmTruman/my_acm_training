#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck() cout<<"fuck:"<<__LINE__<<endl;
using namespace std;
typedef long long ll;

const int maxn = 50020;
int n,m,k,a,b;
bool visit[maxn];
int fa[maxn];
void init(){
	for(int i = 0;i<=n;i++)fa[i] = i;
	clr(visit,0);
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
	while(cin>>n>>m&&!(m==0&&n==0)){
		init();
		for(int i = 0;i<m;i++){
			cin>>k>>a;
			for(int j = 0;j<k-1;j++){
				cin>>b;
				join(a,b);
			}
		}
		int ans = 1;
		for(int i = 1;i<n;i++){
			if(find(i) == find(0))ans++;
		}
		cout<<ans<<endl;
		
	}
} 