#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck() cout<<"fuck:"<<__LINE__<<endl;
using namespace std;
typedef long long ll;

const int maxn = 1020;
int n,m;
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
	while(cin>>n&&n){
		init();
		cin>>m;
		while(m--){
			int a,b;cin>>a>>b;join(a,b);
		}
		int num = 0;
		for(int i = 1;i<=n;i++){
			if(!visit[find(i)]){
				visit[find(i)] = true;
				num ++;
			}
		}
		cout<<num-1<<endl;
	}
} 