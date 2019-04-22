#include <iostream>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

bool vis[200020];
int n,k;
int temp;
stack<int>S;
vector<int>V;
vector<int>aa;
int main()
{
	cin >> n >> k;
	int now = 1;
	for(int i = 0;i<k;i++)cin >> temp,aa.push_back(temp);	
	for(int i = 0;i<k;i++)
	{
		while(!S.empty() && now == S.top())
		{
			S.pop();
			now++;
		}
		temp = aa[i];
		if(temp != now)
		{
			if(S.empty()){
				S.push(temp);
				V.push_back(temp);
			}
			else if(temp > S.top()){
				cout << "-1" << endl;
				return 0;
			}else{
				S.push(temp);
				V.push_back(temp);
				vis[temp] = true;
			}
		}
		else {
			now++;
			V.push_back(temp);
		}
	}
	for(int i = now;i<=n;i++)
	{
		if( !S.empty() && i == S.top())
		{
			vis[i] = false;
			S.pop();
		}
		else if(!vis[i] && !S.empty() && i < S.top()){
			for(int j = S.top() - 1;j>=i;j--){
				V.push_back(j);
			}
			i = S.top();
			S.pop();
		}
		else if(!vis[i] && S.empty()){
			for(int j = n;j>=i;j--)V.push_back(j);
			i = n;
		}else if(vis[i]){
			cout << "-1" << endl;
			return 0;
		}
	}
	
	for(int i = 0;i<V.size();i++){
		cout << V[i] << " ";
	}
	cout << endl;
	
}
