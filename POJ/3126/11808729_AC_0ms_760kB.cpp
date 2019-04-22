#include<iostream>
#include<queue>
#include<string.h>
#include<string>
#include<math.h> 
using namespace std;
const int maxn = 10020;
bool isprime[10020] = {true,true},vis[maxn];
typedef struct _node{
	int x;
	int step;
	_node(int a,int b):x(a),step(b){}
}node;
bool isOK(int a){
	for(int i = 2;i<=sqrt(a);i++){
		if(a%i == 0)return false;
	}
	return true;
}
void init()
{
	for(int i = 2;i<10000;i++)
	{
		if(isOK(i))isprime[i] = true;
	}
}

int main()
{
	init();
	int T;
	cin>>T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		int a,b;cin>>a>>b;
		int flag = 1;
		queue<node>Q;
		node temp(a,0);
		Q.push(temp);
		while(!Q.empty())
		{
			node temp = Q.front();
			Q.pop();
			//cout<<"Debug: "<<temp.x<<","<<temp.step<<"\t"<<endl;
			//cout<<temp.step<<endl;
			if(temp.x == b)
			{
				cout<<temp.step<<endl;
				flag = 0;
				break;
			}
			int k = temp.x%1000;
			for(int i = 1000;i<10000;i += 1000)
			{
				if(isprime[i+k]&&!vis[i+k])
				{
					vis[i+k] = true;
					node t(i+k,temp.step+1);
					Q.push(t);
				}
			}
			k = temp.x%100+temp.x/1000*1000;
			for(int i = 0;i<1000;i+=100)
			{
				if(isprime[i+k]&&!vis[i+k])
				{
					vis[i+k] = true;
					node t(i+k,temp.step+1);
					Q.push(t);
				}
			}
			k = temp.x%10+temp.x/100*100;
			for(int i = 0;i<100;i+=10)
			{
				if(isprime[i+k]&&!vis[i+k])
				{
					vis[i+k] = true;
					node t(i+k,temp.step+1);
					Q.push(t);
				}
			}
			k = temp.x/10*10;
			for(int i =0;i<10;i++)
			{
				if(isprime[i+k]&&!vis[i+k])
				{
					vis[i+k] = true;
					node t(i+k,temp.step+1);
					Q.push(t);
				}
			}
		}
		if(flag)cout<<"Impossible"<<endl;
	} 
} 