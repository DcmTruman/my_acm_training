#include<string.h>
#include<stdio.h>

#define LSon(x) ((x)<<1)
#define RSon(x) ((x)<<1|1)

const int maxn = 50020;
const int root = 1;
int n;
int a,b;


int node[maxn<<2];

void update(int pos)
{
	node[pos] = node[LSon(pos)]+node[RSon(pos)];
}

void build(int l,int r,int pos)
{
	node[pos]= 0;
	if(l == r)
	{
		scanf("%d",&node[pos]);
		return;
	}
	int m = l+r>>1;
	build(l,m,LSon(pos));
	build(m+1,r,RSon(pos));
	update(pos);
}
void modify(int l,int r,int pos,int x,int y)//修改x处为y值，本题中，y可为负数 
{
	if(l==r)
	{
		node[pos] += y;
		return;
	}
	int m = l+r>>1;
	if(x<=m)modify(l,m,LSon(pos),x,y);
	else modify(m+1,r,RSon(pos),x,y);
	update(pos);
} 

int query(int l,int r,int x,int y,int pos)
{
	if(x<=l&&r<=y)
	{
		return node[pos];
	}
	int res = 0;
	int m = l+r>>1;
	if(x<=m)res+=query(l,m,x,y,LSon(pos));
	if(y>m)res+= query(m+1,r,x,y,RSon(pos));
	return res;
}
int main()
{
	int T;
	scanf("%d",&T);
	int _c = T;
	while(T--)
	{
		printf("Case %d:\n",_c-T);
		scanf("%d",&n);
		//memset(node,0,sizeof(node));
		build(0,n-1,root);
		char op[10];
		while(scanf("%s",op))
		{
			if(op[0] == 'E')break;
			scanf("%d%d",&a,&b);
			if(op[0] == 'A')
			{
				modify(0,n-1,root,a-1,b);
			}
			else if(op[0] == 'S')
			{
				modify(0,n-1,root,a-1,-b);
			}
			else if(op[0] == 'Q')
			{
				printf("%d\n",query(0,n-1,a-1,b-1,root));
			}
		}
	}
}