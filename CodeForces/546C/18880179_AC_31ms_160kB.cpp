#include <stdio.h>
#include <utility>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <set>

using namespace std;

set<pair<queue<int> , queue<int> > >S;
queue<int>q1;
queue<int>q2;
int main()
{
	int n;
	cin >> n;
	int n1;cin >> n1;
	for(int i = 0;i<n1;i++){
		int a;cin >> a;
		q1.push(a);
	}
	int n2;cin >> n2;
	for(int i = 0;i<n2;i++){
		int a;cin >> a;
		q2.push(a);
	}
	int ans = 0;
	while((!q1.empty()) && (!q2.empty()))
	{
		
		if(S.count(make_pair(q1,q2))){
			cout << "-1" << endl;
			return 0;
		}
		S.insert(make_pair(q1,q2));
		ans ++;
		int aa = q1.front();
		int bb = q2.front();
		q1.pop();q2.pop();
		if(aa > bb){
			q1.push(bb);
			q1.push(aa);
		}else{
			q2.push(aa);
			q2.push(bb);
		}
	}
	if(q1.empty()){
		cout << ans << " 2" <<endl;
	}else{
		cout << ans << " 1" << endl;
	}

}
