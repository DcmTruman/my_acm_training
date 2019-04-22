#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <stack>

using namespace std;

stack<char>S;
int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	int le = s.length();
	for(int i = 0;i<le;i++){
		if(!S.empty()){
			if(S.top() == s[i]){
				S.pop();
				cnt ++;
			}else{
				S.push(s[i]);
			}
		}	
		else{
			S.push(s[i]);
		}
	}
	if(cnt&1)cout << "Yes" << endl;
	else cout << "No" << endl;
}
