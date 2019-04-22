#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck() cout<<"fuck:"<<__LINE__<<endl;
using namespace std;
typedef long long ll;

const int maxn = 100020;
bool visit[maxn];
int fa[maxn];
void init(){
	for(int i = 0;i<maxn;i++)fa[i] = i;
} 

int find(int x){
	return (fa[x] == x)?x:fa[x] = find(fa[x]);
}


int main()
{
	int a,b;
	int cnt = 0;
	while(cin>>a>>b&&!(a==-1&&b==-1)){
		clr(visit,0);
		if(a == 0&&b == 0){
			cout<<"Yes"<<endl;
			continue;
		}
		init();
		bool flag = true;
		int mx = max(a,b);
		do{
			mx = max(mx,max(a,b));
			visit[a] = true;
			visit[b] = true;
			int x = find(a);
			int y = find(b);
			if(x==y)flag = false;
			else fa[x] = y;
		}while(cin>>a>>b&&!(a==0&&b==0));
		for(int i = 1;i<=mx;i++){
			if(visit[i]){
				if(find(i)!=find(mx)){
					flag = false;
					break;
				}
			}
		}
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 





