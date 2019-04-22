#include<iostream>  
#include<string.h>  
using namespace std;
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,1 },{ 0,-1 } };//分别代表四个行进的方向，代表左右上下    
char arr[25][25];//根据题意，读入初始的位置，最大的是20，多申请几个保险。  
struct node
{
	int x, y, step;
}queue[25 * 25];//分别代表坐标xy，和这个是第几步  
int vis[25][25];//代表是否走过这个地方。  
int w, h;
int bfs(int p, int q) {
	memset(vis, 0, sizeof(vis));
	int i, a, b, top, t;
	node temp;
	top = -1;
	t = -1;
	t++;
	vis[p][q] = 1;
	queue[t].x = p;
	queue[t].y = q;//初始化队列  
	queue[t].step = 1;//塞入队列；  
	while (t != top) {//队列不为空；  
		top++;
		temp.x = queue[top].x;//pop出队列，出第一个   
		temp.y = queue[top].y;

		for (i = 0; i<4; i++) {
			a = temp.x + dir[i][0];
			b = temp.y + dir[i][1];
			if (a >= 0 && a<w&&b >= 0 && b<h&&arr[a][b] != '#'&&vis[a][b] == 0)
			{
				t++;
				queue[t].x = a;
				queue[t].y = b;
				queue[t].step = queue[t - 1].step + 1;//可以走时，入队；  
				vis[a][b] = 1;
			}
		}
	}
	return queue[t].step;
}

int main(){

	int i, j, count, a, b;
	while (scanf("%d%d", &h, &w) != EOF)
	{
		if (!h && !w)
			break;
		for (i = 0; i<w; i++) {
			scanf("%s", &arr[i]);
			for (j = 0; j<h; j++)
				if (arr[i][j] == '@') {
					a = i;
					b = j;

				}
		}
		count = bfs(a, b);
		printf("%d\n", count);
	}
	return 0;
}