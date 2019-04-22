#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<math.h>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck() cout<<"fuck:"<<__LINE__<<endl;
using namespace std;
typedef long long ll;

const int maxn = 1e5+7;

int fa[maxn*2+20],high[maxn*2+20];
bool sure[maxn];
int n,m,a,b;
char c;

void init(){
	for(int i = 1;i<2*maxn+2;i++){
		fa[i] = i;
		high[i] = 0;
	}
}

int find(int x){
	return (fa[x] == x)?x:fa[x] = find(fa[x]);
}

void join(int a,int b){
	int x = find(a);
	int y = find(b);
	//cout<<x<<" "<<y<<endl;
	if(x!=y){
		if(high[x]<high[y])fa[x] = y;
		else{
			fa[y] = x;
			if(high[x] == high[y])high[x]++;
		}
	}
}


int main()
{	
	ios::sync_with_stdio(false);
	int T;scanf("%d",&T);
	while(T--){
		//clr(sure,0);
		scanf("%d%d",&n,&m);
		//getchar();
		init();
		for(int i = 0;i<m;i++){
			//getchar();
			//cout<<i<<endl;
			scanf("\n%c%d%d",&c,&a,&b);
			//getchar();
			if(c == 'A'){
				//cout<<find(a)<<find(b);
				
				if(find(a) == find(b+n)||find(b) == find(a+n))printf("In different gangs.\n");
				else if(find(a) == find(b)||find(a+n) == find(b+n))printf("In the same gang.\n");
				else printf("Not sure yet.\n");
			}
			else if(c == 'D'){
				join(a,b+n);
				join(a+n,b);
			}
		}
	}
	return 0;
	
} 