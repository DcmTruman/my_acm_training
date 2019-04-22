#include<iostream>

using namespace std;

const int maxn = 150020;

int fa[maxn];

int n,k;
void init()
{
	for(int i = 0;i<3*n;i++)
	{
		fa[i] = i;
	}
}
int find(int x)
{
	return (fa[x] == x)?x:fa[x] = find(fa[x]);	
}

void merge(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx!=fy)
	{
		fa[fx] = fy;
	}
}
bool isOK(int x,int y,int t)
{
	if(x == y&&t!=1)return false;
	if(x>n||y>n)return false;
	
	if(t == 1)
	{
		if(find(x) == find(y+n)||find(x) == find(y+2*n))return false;
		else return true;
	}
	else
	{
		if(find(x) == find(y)||find(x) == find(y+2*n))return false;
		else return true;
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	int ans = 0;
	init();
	while(k--)
	{
		int x,y,t;
		scanf("%d%d%d",&t,&x,&y);
		if(isOK(x,y,t))
		{
			if(t == 1)
			{
				merge(x,y);
				merge(x+n,y+n);
				merge(x+2*n,y+2*n);
			}
			else
			{
				merge(x,y+n);
				merge(x+n,y+2*n);
				merge(x+2*n,y);
			}
		}
		else ans++;	
	}
	cout<<ans<<endl;	
} 