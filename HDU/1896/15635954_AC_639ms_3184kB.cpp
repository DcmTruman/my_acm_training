#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck() cout<<"fuck:"<<__LINE__<<endl;
using namespace std;
typedef long long ll;

const int maxn = 50020;
int n;
struct node{
	int p;
	int d;
	bool operator < (const node b)const{
		if(p == b.p)return d>b.d;
		return p>b.p;
	}
};
node temp;
int main()
{
	
	int T;cin>>T;
	while(T--)
	{
		priority_queue<node>q;
		cin>>n;
		for(int i = 0;i<n;i++){
			int a,b;cin>>a>>b;
			q.push(node{a,b});
		}
		int sp;
		int ep;
		int a = 0;
		while(!q.empty()){
			
			temp = q.top();
			q.pop();
			//cout<<temp.p<<endl;
			ep = temp.p;
			a++;
			if(a&1){
			//	cout<<"fuck"<<endl;
				q.push((node){temp.p+temp.d,temp.d});	
			}
		}
		cout<<ep<<endl;
	}

	return 0;
} 