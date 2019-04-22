#include<iostream>
#include<stack>
#include<string>
#include<string.h>

using namespace std;

int p,q;
int T;
int flag;

struct node{
	int x,y;
};
stack<node>S;
stack<node>S1;
int mx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int my[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
bool visit[100][100];

bool isOK(int x,int y)
{
	if(x<0||y<0||x>=p||y>=q||visit[x][y]||flag)return false;
	return true;
}

void dfs(int x,int y,int step)
{
	if(flag)return;
	if(step == p*q)
	{
		flag = true;
		return;
	}
	for(int i = 0;i<8;i++)
	{
		int xx = x + mx[i];
		int yy = y + my[i];
		if(isOK(xx,yy))
		{
			visit[xx][yy] = true;
			node temp;
			temp.x = xx;
			temp.y = yy;
			S.push(temp);
			dfs(xx,yy,step+1);
			if(flag)return;
			visit[xx][yy] = false;
			S.pop();
		}
		if(flag)return;
	}
}

int main()
{
	cin>>T;
	for(int tt = 1;tt<=T;tt++)
	{
		while(!S.empty())S.pop();
		while(!S1.empty())S1.pop();
		memset(visit,0,sizeof(visit));
		flag = false;
		cin>>p>>q;
		node temp;
		temp.x = 0;
		temp.y = 0;
		S.push(temp);
		visit[0][0] = true;
		dfs(0,0,1);
		printf("Scenario #%d:\n",tt);
		if(flag)
		{
			while(!S.empty())
			{
				S1.push(S.top());
				S.pop();
			}
			while(!S1.empty())
			{
				node t = S1.top();
				S1.pop();
				cout<<(char)(t.y+'A')<<t.x+1;
			}
		}
		else
		{
			cout<<"impossible";
		}
		
		cout<<endl;
		if(tt!=T)cout<<endl;
	}
}