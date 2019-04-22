#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<int>V;
set<int>S;

int main()
{
	int n, k = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		V.push_back(temp);
	}
	if (n == 1)cout << "-1";
	sort(V.begin(), V.end());
	if (n == 2)
	{
		int t = V[1] - V[0];
		if (t)
		{
			if (t & 1)
			{
				cout << "2\n" << V[0] - t << " " << V[1] + t;
			}
			else
			{
				cout << "3\n" << V[0] - t << " " << V[0] + t / 2 << " " << V[1] + t;
			}
		}
		else
		{
			cout << "1\n" << V[0];
		}
	}
	else if (n > 2)
	{
		int mindis = 99999999999;
		int count = 0, p = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (V[i + 1] - V[i] < mindis)
			{
				mindis = V[i + 1] - V[i];
			}
		}
		for (int i = 0; i < n - 1; i++)
		{
			if (V[i + 1] - V[i] != mindis)
			{
				count++;
				p = i;
			}

		}
		if (count == 0 && mindis != 0)
			cout << "2\n" << V[0] - mindis << " " << V[n - 1] + mindis;
		else if (count == 0 && mindis == 0)
			cout << "1\n" << V[0];
		else if (count == 1 && (V[p + 1] - V[p]) == 2 * mindis)
			cout << "1\n" << V[p] + mindis;
		else
			cout << "0";
	}
	
}