#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
#include<string>
#define clr(x,b) memset(x,(b),sizeof(x))

using namespace std;


struct edge{
	int u;
	int v;
	string s;
};
vector<int>S;
const int maxn =  100020;
const int maxm = 100020;
edge V[maxn];
bool v[maxn];
bool visit[maxn];
int ru[maxn];
int chu[maxn];
int fa[maxn];
int n;
bool flag;
string s;

bool cmp(edge a,edge b){
	return a.s<b.s;
}
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

void dfs(int a){
	for(int i = 1;i<=n;i++){
		if(!v[i]&&V[i].u == a){
			v[i] = true;
			dfs(V[i].v);
			S.push_back(i);
		}
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		init();
		clr(ru,0);
		clr(chu,0);
		clr(v,0);
		clr(visit,0);
		S.clear();
		for(int i = 1;i<=n;i++){
			
			cin>>s;
			V[i].s = s;
			V[i].u = s[0]-'a'+1;
			V[i].v = s[s.length()-1]-'a'+1;//cout<<"fucl"<<endl;
			chu[V[i].u]++;
			ru[V[i].v]++;
			visit[V[i].u] = true;
			visit[V[i].v] = true;
		//	cout<<"fuck"<<endl;
			join(V[i].u,V[i].v);
		}
		sort(V+1,V+n+1,cmp);
		flag = true;
		int t = 0;
		for(int i = 1;i<=26;i++){
			if(visit[i]){
				if(t == 0)t = find(i);
				if(find(i)!=t){
					flag = false;
					break;
				}
			}
		}
		int cnt1 = 0;
		int cnt2 = 0;
		int p1 = 0;
		for(int i = 1;i<=26;i++){
			if(visit[i]){
				if(chu[i]!=ru[i]){
					if(abs(chu[i]-ru[i])>1){
						//cout<<"fucl"<<endl;
						flag = false;
						break;
					}
					if(chu[i]-ru[i] ==1)cnt1++;
					else if(ru[i]-chu[i] == 1)cnt2++;
					if(chu[i]>ru[i])p1 = i;
			 	}	
			}
		}
		if(cnt1>1||cnt2>1||cnt1!=cnt2)flag = false;
		if(cnt1==0&&cnt2==0){
			for(int i = 1;i<=26;i++){
				if(visit[i]){
					p1 = i;
					break;
				}
			}
		}
		if(!flag){
			cout<<"***"<<endl;
			continue;
		}
		dfs(p1);
		for(int i = S.size()-1;i>0;i--)cout<<V[S[i]].s<<".";
		cout<<V[S[0]].s<<endl;
		
	}
}