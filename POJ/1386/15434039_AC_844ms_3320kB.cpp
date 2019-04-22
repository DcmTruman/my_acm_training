#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
#include<string>
#define clr(x,b) memset(x,(b),sizeof(x))

using namespace std;
const int maxn =  100020;
const int maxm = 100020;
vector<int>V[maxn];
vector<int>S;
bool visit[maxn];
int ru[maxn];
int chu[maxn];
int fa[maxn];
int n;
bool flag;
string s;

void init(){
	for(int i = 1;i<=26;i++){
		fa[i] = i;
	}
}

int find(int x){
	return (fa[x] == x)?x:fa[x] = find(fa[x]);
}

void join(int x,int y){
	int a = find(x);
	int b = find(y);
	if(a!=b)fa[a] = b;
}

int main()
{
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		init();
		clr(chu,0);
		clr(ru,0);
		clr(visit,0);
		for(int i = 0;i<=26;i++)V[i].clear();
		S.clear();
		clr(visit,0);
		int t;
		for(int i = 0;i<n;i++){
			cin>>s;
			int x = s[0]-'a';
			int y = s[s.length()-1]-'a';
			t = x;
			V[x].push_back(y);
			join(x,y);
			chu[x]++;
			ru[y]++;
			visit[x] = true;
			visit[y] = true;
		}
		int cnt1 = 0;
		int cnt2 = 0;
		bool flag = true;
		
		for(int i = 0;i<26;i++){
			if(visit[i]){
				if(find(i)!=find(t)){
					flag = false;
					break;
				}
			}
			
		}
		for(int i = 0;i<26;i++){
			if(visit[i]){
				if(chu[i]-ru[i] == 1){
					cnt1++;
				}
				else if(ru[i]-chu[i] == 1){
					cnt2++;
				}
				else if(chu[i]-ru[i]>1||ru[i]-chu[i]>1){
					flag = false;
					break;
				}
			}
			//cout<<chu[i]<<" "<<ru[i]<<endl;
		}
		if(cnt1>1||cnt2>1)flag =false;
		if(flag)cout<<"Ordering is possible.\n";
		else cout<<"The door cannot be opened.\n";
	}
	return 0;
}