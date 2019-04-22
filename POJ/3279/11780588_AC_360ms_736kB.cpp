#include<iostream>
#include<string>
#include<string.h>

using namespace std;
int n,m,cnt;

int G[16][16],temp[16][16],f[16][16];
int x[4] = {0,0,-1,1};
int y[4] = {1,-1,0,0};

void flip(int i,int j)
{
	cnt++;
	f[i][j] = 1;
	temp[i][j] = !temp[i][j];
	for(int k = 0;k<4;k++)
	{
		if(i+x[k]>-1&&j+y[k]>-1)
		{
			temp[i+x[k]][j+y[k]] ^= 1;
		}
	}
}

bool isOK(int k)
{
	cnt = 0;
	memcpy(temp,G,sizeof(temp));
	for(int i = 0;i<m;i++)
	{
		if(k&(1<<(m-1-i)))
		{
			flip(0,i);
		}
	}
	
	for(int i = 1;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			if(temp[i-1][j])flip(i,j);
		}
	}
	for(int i = 0;i<m;i++)
	{
		if(temp[n-1][i])return false;
	}
	return true;
}
int main()
{
	while(cin>>n>>m)
	{
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				cin>>G[i][j];
			}
		}
		int ans = n*m+1,pos = -1;
		for(int i = 0;i<(1<<m);i++)
		{
			if(isOK(i)&&cnt<ans)
			{
				ans = cnt;
				pos = i;
			}
		}
		memset(f,0,sizeof(f));
		if(pos>=0)
		{
			isOK(pos);
			for(int i = 0;i<n;i++)
			{
				for(int j = 0;j<m;j++)
				{
					if(j)cout<<" "<<f[i][j];
					else cout<<f[i][j];
				}
				cout<<endl;
			}
		}
		else
		{
			cout<<"IMPOSSIBLE"<<endl; 
		}
	}
} 