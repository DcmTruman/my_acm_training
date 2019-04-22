#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

const int maxn = 120;
const int maxm = 10020;

int k = 0;
int n;
int C;
int m;

struct edge{
	int from,to,len,cost;
	int next;
}E[maxm];

int head[maxn];

struct node{
	int di,co,x;
	bool operator<(const node &b)const
	{
        if(di!=b.di)
        {
            return di>b.di;
        }
        else return co>b.co;
    }
};

void addedge(int a,int b,int c,int d)
{
	E[k].from = a;
	E[k].to = b;
	E[k].len = c;
	E[k].cost = d;
	E[k].next = head[a];
	head[a] = k++;
}

int dijk()
{
	priority_queue<node>Q;
	node st;
	st.di = 0;
	st.co = 0;
	st.x = 1;
	Q.push(st);
	while(!Q.empty())
	{
		node t = Q.top();
		Q.pop();
		if(t.x == n)return t.di;
		
		for(int i = head[t.x];i!=-1;i=E[i].next)
		{
			if(t.co+E[i].cost<=C)
			{
				node temp;
				temp.co = t.co+E[i].cost;
				temp.di = t.di+E[i].len;
				temp.x = E[i].to;
				Q.push(temp);
			}
		}
	}
	return -1;
}

int main()
{
	cin>>C;
	cin>>n;
	cin>>m;
	memset(head,-1,sizeof(head));
	for(int i = 0;i<m;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		addedge(a,b,c,d);
	}
	cout<<dijk()<<endl;
}

