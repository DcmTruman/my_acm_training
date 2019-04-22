#include<iostream>
#include<vector>

using namespace std;
vector<int>V;
int T[30010];
int main()
{
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n-1; i++) {
		cin >> T[i];
	}
	V.resize(n+5);
	for (int i = 1; i < n; i++) {
		V[i] = i + T[i];
	}
	int pos = 1;
	while (pos < n&&pos!=t)
	{
		pos = V[pos];
	}
	if (pos == t)cout << "YES" << endl;
	else cout << "NO" << endl;
	
}