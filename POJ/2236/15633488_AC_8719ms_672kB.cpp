#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck() cout<<"fuck:"<<__LINE__<<endl;
using namespace std;
typedef long long ll;

const int maxn = 50020;
int n,m,k,a,b,d,p,q;
char c;
int fa[maxn];

struct node{
	int x;
	int y;
	int id;
	bool re;
};

node V[1020];
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

double dis(int a,int b){
	return sqrt((V[a].x-V[b].x)*(V[a].x-V[b].x)+(V[a].y-V[b].y)*(V[a].y-V[b].y));
}
int main()
{
	cin>>n>>d;
	init();
	for(int i = 0;i<n;i++){
		cin>>V[i+1].x>>V[i+1].y;
		V[i+1].id = i+1;
		V[i+1].re = false;
	}
	while(cin>>c){
		if(c == 'O'){
			cin>>p;
			V[p].re = true;
			for(int i = 1;i<=n;i++){
				if(dis(p,i)<=d&&V[i].re)join(p,i);
			}
		}
		else if(c == 'S'){
			cin>>p>>q;
			//cout<<"**"<<find(p)<<"**"<<find(q)<<endl;
			if(find(p) == find(q))cout<<"SUCCESS"<<endl;
			else cout<<"FAIL"<<endl;
		}
	}
	
	
} 