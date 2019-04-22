#include<iostream>
#include<queue>
#include<string.h>
#include<stdio.h>
#include<string>
using namespace std;

bool map[35][35][35], visit[35][35][35];
int movex[6] = { 1,0,-1,0,0,0 };
int movey[6] = { 0,-1,0,1,0,0 };
int movez[6] = { 0,0,0,0,1,-1 };

int L, R, C;

typedef struct _node {
	int x, y, z, step;

}node;

queue<node>Q;
node S, E;
bool isOK(int x, int y, int z)
{
	if (x<0 || x >= R || y<0 || y >= C || z<0 || z >= L)return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	bool Debug = false;
	while (cin >> L >> R >> C)
	{
		if (L == 0 && R == 0 && C == 0) {
			break;
		}
		for (int l = 0; l<L; l++)
		{
			for (int i = 0; i<R; i++)
			{
				char s;
				//cin>>s;
				//cout<<"Debug: "<<s<<endl;
				for (int j = 0; j<C; j++)
				{
					cin >> s;
					if (s == '.')
					{
						//cout<<"***"<<endl;
						map[l][i][j] = 1;
					}
					else if (s == '#')
					{
						//cout<<"***"<<endl;
						map[l][i][j] = 0;
					}
					else if (s == 'S')
					{
						//cout<<"***"<<endl;
						map[l][i][j] = 1;
						S.x = i; S.y = j; S.z = l; S.step = 0;
					}
					else
					{
						//cout<<"***"<<endl;
						map[l][i][j] = 1;
						E.x = i; E.y = j; E.z = l; E.step = 0;
					}
				}
			}
		}

		Q.push(S);
		bool flag = false;
		int Step;
		while (!Q.empty())
		{
			node Now = Q.front();
			Q.pop();
			if (Now.x == E.x&&Now.y == E.y&&Now.z == E.z)
			{
				flag = true;
				Step = Now.step;
				break;
			}
			for (int i = 0; i<6; i++)
			{
				int xx = Now.x + movex[i];
				int yy = Now.y + movey[i];
				int zz = Now.z + movez[i];
				if (isOK(xx, yy, zz) && !visit[zz][xx][yy] && map[zz][xx][yy])
				{
					node temp;
					temp.x = xx;
					temp.y = yy;
					temp.z = zz;
					temp.step = Now.step + 1;
					visit[zz][xx][yy] = true;
					Q.push(temp);
				}
			}
		}
		if (flag)cout << "Escaped in " << Step << " minute(s)." << endl;
		else cout << "Trapped!" << endl;
		while (!Q.empty())Q.pop();
		memset(map,0,sizeof(map));
		memset(visit, 0, sizeof(visit));
	}
}