#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
   return a>b;
}
typedef struct _RATE
{
   int x,y;
}Rate;
int main()
{
	int N;
	cin >> N;
	vector<Rate>V;
	int flag = 1;
	for (int i = 0;i<N;i++){
		int a,b;
		cin>>a>>b;
		Rate temp = {a,b};
		V.push_back(temp);
		if(V[i].x != V[i].y){
			flag = 0;
		}
	}
	if (!flag){
		cout<<"rated";
	}
	else{
		flag = 0;
		vector<int>Temp;
		for (int i = 0;i<N;i++){
			Temp.push_back(V[i].x);
	}
		sort(Temp.begin(),Temp.end(),cmp);
		for (int i = 0;i<N;i++){
			if(V[i].x!=Temp[i]){
				flag = 1;
				break;
			}
	}
		if(flag)cout<<"unrated";
		else cout<<"maybe";
	}
}