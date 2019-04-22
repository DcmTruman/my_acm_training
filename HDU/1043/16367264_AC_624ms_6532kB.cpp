/*-----------------------------------------
作者：邓楚盟
日期：2018年10月10日
耗时：700ms
-----------------------------------------*/
#include <iostream>
#include <functional>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
//---------------全局常量-------------------
const int maxn = 400000;

//---------------变量定义--------------------

struct node{
    int maze[3][3];//用来表示当前状态
    int h,g;//f(x) = g(x) + h(x)
    int x,y;//当前空位的位置
    int node_hash;//当前状态的全排列hash值
    bool operator < (const node b) const{//f(x)越大的优先级越小
        return h + g > b.h + b.g;
    }
};
struct _path{
    int pre;
    char ch;
}path[maxn];
//---------------全局变量--------------------
node s,u,v;
int fact_hash[9] = {1,1,2,6,24,120,720,5040,40320}; //用来计算hash的阶乘数组，定义0! = 1
int dest_node_hash= 322560;//终结节点的hash值
int vis[maxn];//用来记录是否访问过
int pre[maxn];//每个点的前向节点，回溯时可以打印路径
int mv[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};   //朝四个方向进行移动
char dir[4] = {'u','d','l','r'};//移动对应的字母
//----------------函数定义-------------------

int get_hash(node now)//获取当前状态的全排列hash值
{
    int a[9];
    int k = 0;
    //将当前矩阵展开至一维
    for (int i = 0;i < 3;i ++){
        for(int j = 0;j < 3;j ++){
            a[k++] = now.maze[i][j];
        }
    }
    int ret = 0;
    //计算hash值
    for(int i = 0;i<9;i++){
        int k = 0;//统计逆序对
        for(int j = 0;j<i;j++){
            if(a[j] > a[i]){
                k ++;
            }
        }
        ret += fact_hash[i] * k;
    }
    return ret;
}

int get_h(node now)//计算当前节点到终止节点的估计代价
{
    int ret = 0;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(now.maze[i][j]){
                ret += abs(i-(now.maze[i][j]-1)/3)+abs(j-(now.maze[i][j]-1)%3);
            }
        }
    }
    return ret;
}

void show(int x)
{
    //回溯打印到达当前状态的路径
    if(path[x].pre == -1)return;
    show(path[x].pre);
    printf("%c",path[x].ch);
} 

void A_star(node e)
{
    memset(vis,0,sizeof(vis));
    node a,b;
    e.node_hash = get_hash(e);
    e.g = 0;
    e.h = get_h(e);
    vis[e.node_hash] = 1;
    path[e.node_hash].pre = -1;
    if(e.node_hash == dest_node_hash){printf("\n");return;}
    priority_queue<node>q;
    q.push(e);
    while(!q.empty()){
        e = q.top();
        q.pop();
        for(int i = 0;i<4;i++){
            int xx = e.x + mv[i][0];
            int yy = e.y + mv[i][1];
            if(xx<0||yy<0||xx>=3||yy>=3)continue;
            a = e;
            swap(a.maze[e.x][e.y],a.maze[xx][yy]);
            int k = get_hash(a);
            if(vis[k])continue;
            vis[k] = true;
            a.node_hash = k;
            a.x = xx;
            a.y = yy;
            a.g++;
            a.h = get_h(a);
            path[k].pre = e.node_hash;
            path[k].ch = dir[i];
            if(k == dest_node_hash){
                //到达终止节点，打印
                show(k);
                printf("\n");
                return;
            }
            q.push(a);
        }
    }

}

bool has_solution(node e)
{
    int k = 0;
    for(int i=0;i<9;i++)
    {
        if(e.maze[i/3][i%3]==0)continue;
        for(int j=0;j<i;j++)
        {
            if(e.maze[j/3][j%3]==0)continue;
            if(e.maze[j/3][j%3]>e.maze[i/3][i%3])k++;
        }
    }
    if(k&1)return false;
    return true;
}

int main()
{
    char a[30];
    while(gets(a)){
        node start;
        int n = strlen(a);
        for(int i = 0,j = 0;i<n;i++){
            if(a[i] == ' ')continue;
            if(a[i] == 'x'){
                start.maze[j/3][j%3] = 0;
                start.x = j/3;
                start.y = j%3;
            }else{
                start.maze[j/3][j%3] = a[i] - '0';
            }
            j++;
        }
        if(has_solution(start))A_star(start);
        else printf("unsolvable\n");
    }
}
