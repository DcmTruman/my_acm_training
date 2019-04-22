#include <iostream>
#include <stdio.h>

#define ll long long
#define LL long long
using namespace std;
const int MAXN = 50;
ll C[50][50]; 
 

int main()
{
	for (int i = 0; i <= 30; ++i) {
		C[i][0] = 1  ;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) ;
		}
    }
	string ss;
	cin >> ss;
	int lln = ss.length();
	for(int i = 0 ; i<lln-1;i++){
		if(ss[i+1] < ss[i]){
			cout << "0" << endl;
			return 0;
		}
	}

	ll ans = 0;
	for(ll i = 1;i<lln;i++) ans += C[26][i];
	char last_c = 'a';
	for(int i = 0;i<lln;i++){
		for(int j = last_c;j<ss[i];j++)	ans += C['z' - j][lln - i - 1];
		last_c = ss[i] + 1;
	}
	cout << ans + 1 << endl;
}
