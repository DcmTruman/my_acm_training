#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>

using namespace std;
int cnt = 0;
typedef long long ll;

ll num[600000];



void dfs(int n1, int n2, int l, ll number)
{
	if (n1 == l && n2 == l)
	{
		num[cnt++] = number;
		return;
	}
	if (n1<l)
	{
		dfs(n1 + 1, n2, l, number * 10 + 4);
	}
	if (n2<l)
	{
		dfs(n1, n2 + 1,l, number * 10 + 7);
	}
}
int main()
{
	for (int i = 1; i <= 9; i++)
	{
		dfs(0, 0, i, 0);
	}
	//sort(num, num + cnt);
	int C;
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		ll N;
		cin >> N;
		//cout << cnt << N << num[cnt - 1] << endl;
		if (N>num[cnt - 1])
		{
			cout << "44444444447777777777" << endl;
		}
		else
		{
			int pos = lower_bound(num, num + cnt, N) - num;
			cout << num[pos] << endl;
		}
	}
	
}