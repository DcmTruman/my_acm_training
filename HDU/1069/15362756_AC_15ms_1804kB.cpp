#include<iostream>
#include<string.h>
#include<algorithm>
#define clr(x) memset(x,0,sizeof(x))
#define fdbg cout<<"fuck"<<endl;
using namespace std;

struct node{
	int x,y,z;
};

bool cmp(node a,node b){
	if(a.y!=b.y)return a.y<b.y;
	return a.x<b.x;
}
bool isOK(node a,node b){
	if(a.x<b.x&&a.y<b.y)return true;
	return false;
}

node aa[200];
int cnt = 0;
int n,x,y,z;
int dp[200];

int main()
{
	int t = 0;
	while(cin>>n&&n){
		t++;
		cnt=0;
		for(int i = 0;i<n;i++){
			cin>>x>>y>>z;
			aa[cnt].x = x;aa[cnt].y=y;aa[cnt].z=z;
			cnt++;
			aa[cnt].x = y;aa[cnt].y=x;aa[cnt].z=z;
			cnt++;
			aa[cnt].x = y;aa[cnt].y=z;aa[cnt].z=x;
			cnt++;
			aa[cnt].x = z;aa[cnt].y=y;aa[cnt].z=x;
			cnt++;
			aa[cnt].x = x;aa[cnt].y=z;aa[cnt].z=y;
			cnt++;
			aa[cnt].x = z;aa[cnt].y=x;aa[cnt].z=y;
			cnt++;
		}
		//cout<<"fuck"<<endl;
		sort(aa,aa+6*n,cmp);
		clr(dp);
		dp[0] = aa[0].z;
		for(int i = 1;i<cnt;i++){
			//fdbg
			int mx = 0;
			for(int j = 0;j<i;j++){
				if(isOK(aa[j],aa[i]))mx = max(mx,dp[j]);
		 	}
			dp[i]=aa[i].z+mx;
		}
		//fdbg
		int mx = 0;
		//for(int i = 0;i<cnt;i++)cout<<dp[i]<<" ";
		for(int i = 0;i<cnt;i++)mx = max(mx,dp[i]);
		cout<<"Case "<<t<<": maximum height = "<<mx<<endl;
	}
}
