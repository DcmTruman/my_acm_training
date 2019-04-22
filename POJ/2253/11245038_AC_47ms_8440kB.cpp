#include<iostream>
#include <algorithm>
#include<queue>

#include<string.h>

#include <cmath> 
#define INF 0x3fffffff
using namespace std;
int n, m;
double map[1020][1020];
double dis[1020];
bool visit[1020];
void djks(int s)
{
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= n; i++)
	{
		dis[i] = INF;
	}
	dis[1] = 0;
	//visit[s] = true;
	dis[s] = 0;
	for (int i = 1; i <= n; i++)
	{
		double m = INF;
		int pos = INF;
		for (int j = 1; j <= n; j++)
		{
			if (!visit[j] && dis[j]<=m)
			{
				m = dis[j];
				pos = j;
			}
		}
		//cout << pos << endl;
		//if (min == INF)break;
		visit[pos] = true;
		for (int j = 1; j <= n; j++)
		{
			
			{
				//cout << j << "***" << dis[j] << endl;
				dis[j] = min(dis[j],max(map[pos][j],dis[pos]));
				//cout << j << "+++" << dis[j] << endl;
				
			}
		}
	}
}
struct ggg { double x; double y; }Node[1020];
int main()
{
	int t = 0;
	while (cin >> n&&n)
	{
		for (int i = 0; i < 1020; i++) {
			for (int j = 0; j < 1020; j++) {
				map[i][j] = 0;
			}
		}
		int a, b;
		for (int i = 1; i <=n; i++)
		{
			cin >> a >> b;
			Node[i].x = a;
			Node[i].y = b;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				map[i][j] = sqrt(pow((Node[i].x - Node[j].x), 2) + pow((Node[i].y - Node[j].y), 2));
				map[j][i] = sqrt(pow((Node[i].x - Node[j].x), 2) + pow((Node[i].y - Node[j].y), 2));
				//cout << i << j << map[i][j]<<endl;
			}
		}
		djks(1);
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++t, dis[2]);
	}

}