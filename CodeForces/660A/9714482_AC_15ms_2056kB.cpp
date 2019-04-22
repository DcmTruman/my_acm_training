#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int isCoPrime(int x, int y)
{
	int temp;
	while (y)
	{
		temp = x;
		x = y;
		y = temp%x;
	}
	if (x == 1)return x;
	else return 0;
}
int main()
{
	int N;
	cin >> N;
	vector<int> V;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		V.push_back(a);
	}
	//sort(V.begin(), V.end());
		int j = 0;
		while (j < V.size() - 1)
		{
			if (isCoPrime(V[j], V[j + 1]))j++;
			else
			{
				vector<int>::iterator it;
				it = V.begin() + j + 1;
				V.insert(it, 1);
			}
		}
	cout << V.size()-N << endl;
	for (int i = 0; i < V.size(); i++)
	{
		if (i == 0)cout << V[i];
		else cout << " " << V[i];
	}
}