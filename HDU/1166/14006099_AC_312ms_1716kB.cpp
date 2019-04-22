#include<string.h>
#include<stdio.h>

#define LSon(x) ((x)<<1)
#define RSon(x) ((x)<<1|1)
#define lowbit(x) (x&(-x))
const int maxn = 50020;
const int root = 1;
int n;
int a,b;
int sum[maxn];
void add(int pos,int val)
{
	while(pos<=n)
	{
		sum[pos] += val;
		pos += lowbit(pos);
	}
}

int query(int pos)
{
	int res = 0;
	while(pos>0)
	{
		res += sum[pos];
		pos -= lowbit(pos);
	}
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
		memset(sum,0,sizeof(sum));
		for(int i = 1;i<=n;i++)
		{
			int aa;
			scanf("%d",&aa);
			add(i,aa);
		}
		char op[10];
		while(scanf("%s",op))
		{
			if(op[0] == 'E')break;
			scanf("%d%d",&a,&b);
			if(op[0] == 'A')
			{
				add(a,b);
			}
			else if(op[0] == 'S')
			{
				add(a,-b);
			}
			else if(op[0] == 'Q')
			{
				printf("%d\n",query(b)-query(a-1));
			}
		}
	}
}