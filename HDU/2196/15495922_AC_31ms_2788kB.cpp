#include<cstdio>
#include<cstring>
#include<queue>
#define MAXN 99999//这个数是我瞎定的，想要弄小点也可以，不过要超过题目的最小要求啊 
using namespace std;
 
struct node{	int x,y,z,next;		}	a[MAXN];//保存节点信息，next是记录与之相邻的节点的位置信息 
int n,cnt,head[MAXN];//head用来记录每个节点的位置，简单理解就相当于链表指针 
int dis[MAXN],mp;//dis储存位置信息，mp表示最远端点的序号 
 
void add(int i,int b,int c);//添加每个节点的信息，至于为什么能用这种方法能将next指向与之相邻的节点我也不知道→_→套用这样的格式就好 
void bfs(int src);
 
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		cnt=0;		
		memset(head,-1,sizeof(head));
		for(int i=2;i<=n;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			add(i,b,c);
		}
		bfs(1); 
		bfs(mp);//两个连续的bfs是要找到树的直径的第一个端点并更新此端点到任意节点的距离 
		int dis2[n+1];
		for(int i=1;i<=n;i++)
		{
			dis2[i]=dis[i];//把这些距离储存起来 
		}
		bfs(mp);//找另一端点到任意节点的距离，此时mp已被重置为另一端点 
		for(int i=1;i<=n;i++)
		{
			printf("%d\n",dis[i]>dis2[i]?dis[i]:dis2[i]);//比较后输出结果 
		}
	}//我也不知道为什么，突然想在这一行加一个注释 
}
 
void add(int i,int b,int c)
{
	a[cnt].x=i;a[cnt].y=b;a[cnt].z=c;
	a[cnt].next=head[i];
	head[i]=cnt++;
	a[cnt].x=b;a[cnt].y=i;a[cnt].z=c;
	a[cnt].next=head[b];
	head[b]=cnt++;
}
 
void bfs(int src)
{
	int minn=0;
	memset(dis,0,sizeof(dis));
	queue<int>q;
	int vis[MAXN]={0};
	vis[src]=1;
	mp=src;
	q.push(src);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i!=-1;i=a[i].next/*指向下一个*/)
		{
			int y=a[i].y;
			if(!vis[y])
			{
				vis[y]=1;
				dis[y]=dis[x]+a[i].z;				
				q.push(y);
				if(minn<dis[y])
				{
					minn=dis[y];
					mp=y;//不断更新最大距离和端点编号 
				}				
			}
		}
	}
}