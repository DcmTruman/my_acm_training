#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
#include<map>
#define clr(x,b) memset(x,(b),sizeof(x))
#define fuck cout<<"fuck:"<<__LINE__<<endl;
using namespace std;

const int maxn = 100200;
const int maxm  = 100200;

int a[3];
int o[3];
int g[3];
bool visit[100];
int main(){

	int T;
	string s;
	cin>>T;
	while(T--){
		cin>>s;
		clr(visit,0);
		for(int i = 0;i<7;i++){
			if(s[i] == s[i+1]&&s[i+1] == s[i+2]){
				visit[i] = visit[i+1] = visit[i+2] = true;
				break;
			}
		}
		string s1 ="";
		//cout<<s1<<endl;
		//fuck
		for(int i = 0;i<s.length();i++){
			if(!visit[i])s1 += s[i];
			//cout<<s1<<endl;
		} 
		
		//cout<<s1<<endl;
		clr(visit,0);
		s = s1;
		s1 = "";
		for(int i = 0;i<s.length()-2;i++){
			if(s[i] == s[i+1]&&s[i+1] == s[i+2]){
				visit[i] = visit[i+1] = visit[i+2] = true;
				break;
			}
		}
		for(int i = 0;i<s.length();i++){
			if(!visit[i])s1 += s[i];
		} 
		s = s1;
		s1 = "";
		clr(visit,0);
		int ans;
		if(s.length() == 3){
			ans = 3;
			cout<<ans<<endl;
			continue;
		}
		else if(s.length() == 6){
			ans = 2;
			cout<<ans<<endl;
			continue;
		}
		else if(s.length() == 9){
			int mx = -1,mn = 10;
			bool flag1 = false;
			bool flag2 = false;
			for(int i = 0;i<9;i++){
				if(s[i] == 'a'){
					mn = min(mn,i);
					mx = max(mx,i);
				}
			}
			for(int i = mn;i<=mx;i++){
				if(s[i] == 'g')flag1 = true;
				if(s[i] == 'o')flag2 = true;
			}
			if((flag1&&!flag2)||(flag2&&!flag1)){
				ans = 2;
				cout<<ans<<endl;
				continue;
			}
			mx = -1;mn = 10;
			flag1 = false;
			flag2 = false;
			for(int i = 0;i<9;i++){
				if(s[i] == 'g'){
					mn = min(mn,i);
					mx = max(mx,i);
				}
			}
			for(int i = mn;i<=mx;i++){
				if(s[i] == 'a')flag1 = true;
				if(s[i] == 'o')flag2 = true;
			}
			if((flag1&&!flag2)||(flag2&&!flag1)){
				ans = 2;
				cout<<ans<<endl;
				continue;
			}
			mx = -1;mn = 10;
			flag1 = false;
			flag2 = false;
			for(int i = 0;i<9;i++){
				if(s[i] == 'o'){
					mn = min(mn,i);
					mx = max(mx,i);
				}
			}
			for(int i = mn;i<=mx;i++){
				if(s[i] == 'a')flag1 = true;
				if(s[i] == 'g')flag2 = true;
			}
			if((flag1&&!flag2)||(flag2&&!flag1)){
				ans = 2;
				cout<<ans<<endl;
				continue;
			}
			cout<<1<<endl;
		}
	}
}