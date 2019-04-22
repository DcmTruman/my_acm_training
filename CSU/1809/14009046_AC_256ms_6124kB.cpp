#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;


#define LSon(x) ((x)<<1)
#define RSon(x) ((x)<<1|1)


const int maxn = 200020;
const int root = 1;
int n,k;


int pre[maxn];
char cc[maxn];
int node[maxn<<2];

void update(int pos)
{
	node[pos] = min(node[LSon(pos)],node[RSon(pos)]);
}

void build(int l,int r,int pos)
{
	node[pos]= 0;
	if(l == r)
	{
		//cout<<l<<endl;
		node[pos] = pre[l];
		return;
	}
	int m = l+r>>1;
	build(l,m,LSon(pos));
	build(m+1,r,RSon(pos));
	update(pos);
}


int query(int l,int r,int x,int y,int pos)
{
	if(x<=l&&r<=y)
	{
	//cout<<"**"<<node[pos]<<"**"<<pos<<"**"<<endl;
		return node[pos];
	}
	int res = 0x3f3f3f3f;
	
	int m = l+r>>1;
	if(x<=m)res=min(res,query(l,m,x,y,LSon(pos)));
	if(y>m)res=min(res,query(m+1,r,x,y,RSon(pos)));
	return res;
}

int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		memset(pre,0,sizeof(pre));
		memset(node,0x3f3f3f3f,sizeof(node));
		getchar();
		scanf("%s",cc+1);
		for(int i = 1;i<=n;i++)
		{

			if(cc[i] == '(')pre[i] = pre[i-1]+1;
			else pre[i] = pre[i-1] - 1;
		}

		build(1,n,root);
		//for(int i = 1;i<=2*n-1;i++)printf("%d",node[i]);
		for(int i = 0;i<k;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(a>b)
			{
				int ccc = a;
				a = b;
				b = ccc;
			}
			
			if(cc[a] == '('&&cc[b] == ')')
			{

				int d = query(1,n,a,b-1,root);
				if(d>=2)printf("Yes\n");
				else printf("No\n");
			}
			else printf("Yes\n");
		}
	}
}