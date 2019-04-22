#include<iostream>
using namespace std;

int main()
{
	int n, num = 0, a;
	cin >> n;
	while (n--)
	{
		cin >> a;
		num += a - 1;
		if (num & 1)cout << "1" << endl;
		else cout << "2" << endl;
	}
}