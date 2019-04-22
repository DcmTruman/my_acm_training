#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct _FFF
{
	int a;
	int w;
}FFF;
vector<vector<FFF>>V;
int main()
{
	int N,sum = 0;
	cin >> N;
	V.resize(N + 5);
	for (int i = 1; i <= N; i++) {
		int a, b,c;
		cin >> a >> b>>c;
		sum += c;
		FFF temp1 = { b,c };
		V[a].push_back(temp1);
		int d = 0;
		temp1 = { a,d };
		V[b].push_back(temp1);
	}
	int temp = 1, pos = V[1][0].a, m = V[1][0].w;
	while (pos != 1)
	{
		int b = (V[pos][0].a != temp) ? 0 : 1;
		temp = pos;
		m+= V[pos][b].w;
		pos = V[pos][b].a;
	}
	int ans = min(m, sum - m);
	cout << ans << endl;
}