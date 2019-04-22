#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<cstring>
using namespace std;

int aa[30];
int vis[10000];
int main()
{
	int T;cin >> T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		vis[0] = 1;
		int n;cin >> n;
		for(int i = 0;i<n;i++)cin >> aa[i];
		for(int i = 0;i<n;i++){
			int noww = aa[i];
			for(int j = 0;j<2100;j++){
				if(vis[j] == 1){
					if(vis[noww+j] == 0 && noww + j <=2000)vis[noww+j] = -1;
					if(vis[abs(noww-j)] == 0)vis[abs(noww-j)] = -1;
				}
			}
			for(int j = 0;j<2100;j++){
				if(vis[j] == -1)vis[j] =1;
			}
		}
		int m;cin >> m;
		while(m--){
			int a;cin >> a;
			if(a < 0){
				cout << "NO\n";
				continue;
			}
			if(a > 2000){
				cout << "NO\n";
				continue;
			}
			if(vis[a] == 1){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
			
		}
	}
	return 0;
}
