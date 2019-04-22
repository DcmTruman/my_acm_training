#include <iostream>
#include <queue>
using namespace std;
#define min(a,b) (a<b?a:b)
#define MAXV 105
#define MAXINT INT_MAX
 
typedef struct{
	int flow;			//流量
	int capacity;		//最大容量值
}maps;
 
maps map[MAXV][MAXV];
 
int vertime;				//顶点总数
int nedges;					//边的总数
int power_stations;			//发电站总数
int consumers;				//消费者总数
int maxflow;				//最大流
int sp,fp;					//标记源点与汇点
 
int parent[MAXV];			//用于bfs寻找路径
 
 
int bfs(int start,int end){
	int a[MAXV],i,v;
	queue <int>q;
 
	memset(a,0,sizeof(a));
	memset(parent,-1,sizeof(parent));
	
	q.push(start);
	a[start]=MAXINT;
	while(!q.empty()){
		v=q.front();q.pop();
		for(i=1;i<=vertime;i++){
			if(!a[i] && map[v][i].capacity>map[v][i].flow){
				q.push(i);
				parent[i]=v;
				a[i]=min(a[v],map[v][i].capacity-map[v][i].flow);
			}
		}
		if(v==end) break;
	}
	return a[end];
}
 
void EdmondsKarp(){
	int i,tmp;
	maxflow=0;
	while(tmp=bfs(sp,fp)){
		for(i=fp;i!=sp;i=parent[i]){
			map[i][parent[i]].flow-=tmp;			//更新反向流
			map[parent[i]][i].flow+=tmp;			//更新正向流
		}
		maxflow+=tmp;
	}
}
 
int main(){
	int i;
	int x,y,z;
	char ch;
	while(scanf("%d%d%d%d", &vertime, &power_stations,&consumers,&nedges)!= EOF){
		//Init
		memset(map,0,sizeof(map));
 
		//Read Gragh
		for(i=1;i<=nedges;i++){			//设置读图从1开始
			cin>>ch>>x>>ch>>y>>ch>>z;
			map[x+1][y+1].capacity=z;
		}
 
		//Build Gragh
		//建立超级源点指向所有的发电站
		sp=vertime+1;fp=vertime+2;vertime+=2;
		for (i=1; i<=power_stations; i++){
			cin>>ch>>x>>ch>>y;
			map[sp][x+1].capacity=y;
		}
 
		//建立超级汇点，使所有消费者指向它
		for (i=1; i<=consumers; i++){
			cin>>ch>>x>>ch>>y;
			map[x+1][fp].capacity=y;
		}
 
		EdmondsKarp();
		printf("%d\n",maxflow);
	}
}