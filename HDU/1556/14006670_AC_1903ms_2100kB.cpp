#include<string.h>
#include<stdio.h>
#include<iostream>

using namespace std;


#define lowbit(x) (x&(-x))
const int maxn = 100020;

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
	while(cin>>n&&n!=0)
	{
		memset(sum,0,sizeof(sum));
		for(int i = 0;i<n;i++)
		{
			cin>>a>>b;
			add(a,1);
			add(b+1,-1);
		}
		for(int i = 1;i<=n;i++)
		{
			if(i == 1)cout<<query(i);
			else cout<<" "<<query(i);
		}
		cout<<endl;
	} 
}