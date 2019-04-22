#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string STR;
	cin >> STR;
	string temp = STR;
	int number = 1;
	int n = STR.size();
	for (int i = 0; i < n; i++)
	{
		char t = temp[n - 1];
		temp.erase(n - 1, 1);
		temp.insert((string::size_type)0, 1, t);
		if (STR == temp)break;
		number++;
	}
	cout << number;
}