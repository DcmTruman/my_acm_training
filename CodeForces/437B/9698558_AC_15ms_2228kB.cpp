#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lowbit(int a)
{
	return a&(-a);
}
int main()
{
	int sum, limit,temp;
	cin >> sum >> limit;
	vector<int> V;
	for (int i = limit; i >= 1; i--)
	{
		temp = lowbit(i);
		if (sum >= temp)
		{
			sum -= temp;
			V.push_back(i);
		}
	}
	if (sum == 0)
	{
		int l = V.size();
		cout << l << endl;
		for (int i = 0; i < l; i++)
		{
			if (i == 0)
			{
				cout << V[i];
			}
			else
			{
				cout << " "<<V[i] ;
			}
		}
	}
	else
	{
		cout << "-1" << endl;
	}
}