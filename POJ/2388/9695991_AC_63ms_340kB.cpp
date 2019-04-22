#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	vector<int> V;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		V.push_back(temp);
	}
	sort(V.begin(), V.end());
	cout << V[(V.size() + 1) / 2-1];
}