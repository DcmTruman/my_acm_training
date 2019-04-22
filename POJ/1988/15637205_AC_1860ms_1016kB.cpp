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

const int maxn = 30020;

int fa[maxn],num[maxn],dis[maxn];

int n,a,b;
char c;
void init(){
	for(int i = 0;i<=n;i++){
		fa[i] = i;
		num[i] = 1;
		dis[i] = 0;
	}
}

int find(int x){
	if(fa[x] == x){
		return x;
	}
	else
	{
		int temp = fa[x];
		fa[x] = find(fa[x]);
		dis[x] += dis[temp];
		//cout<<"x:"<<x<<"father:"<<fa[x]<<"temp:"<<temp<<endl;
		//if(fa[x]!=temp)num[fa[x]] += num[temp];
		return fa[x];
	}
}

void join(int a,int b){
	int x = find(a);
	int y = find(b);
	//cout<<x<<" "<<y<<endl;
	if(x!=y){
		fa[x] = y;
		dis[x] = num[y];
		num[y] += num[x];
	}
}




int main()
{	

	n = 30020;
	init();
	int p;cin>>p;
	for(int i = 0;i<p;i++){
		cin>>c;
		if(c == 'M'){
			cin>>a>>b;
			join(b,a);
		}
		else if(c == 'C'){
			cin>>a;
			b = find(a);
			cout<<num[b]-dis[a]-1<<endl;;
		}
	}
	
	return 0;
	
} 