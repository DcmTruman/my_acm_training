#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

bool v[12][12];

bool isOK(int a)
{
	int add[12];
	int count = 0;
	memset(add, 0, sizeof(add));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 5; j < 10; j++)
		{
			if (v[i][j])
			{
				if (((a&(1 << i)) == 0) && ((a&(1 << j)) == 0))count++;
				if (((a&(1 << i)) == 0) && ((a&(1 << j))!= 0))add[j]++;
				if (((a&(1 << i)) != 0) && ((a&(1 << j)) == 0))add[i]++;
			}
		}
	}
	if (count > 1)
	{
		return false;
	}
	for (int i = 0; i < 10; i++)
	{
		if (add[i] > 1)return false;
	}
	return true;
}
int main()
{
	int N;
	while (cin >> N)
	{
		memset(v, 0, sizeof(v));
		string s;
		for (int i = 0; i < N; i++)
		{
			cin >> s;
			int t;
			if (s[0] == 'R')t = 0;
			else if (s[0] == 'G')t = 1;
			else if (s[0] == 'B')t = 2;
			else if (s[0] == 'Y')t = 3;
			else if (s[0] == 'W')t = 4;
			int y = s[1] - '0' + 4;
			v[t][y] = true;
		}
		int ans = 0x3f3f3f3f;
		for (int i = 0; i < (1 << 10); i++)
		{
			if (isOK(i))
			{
				int t = i;
				int count = 0;
				while (t)
				{
					if (t&1)
					{
						count++;
					}
					t /= 2;
				}
				ans = min(ans, count);
			}
		}
		cout << ans << endl;
	}
}