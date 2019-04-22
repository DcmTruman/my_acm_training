#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
 char c[70];
int N=0;
string A, B, C;
bool isPoetry(string str)
{
	int len = str.size();
	string temp, AB;
	for (int i = 1; i < len/2; i++) {
		for (int j = 1; j < len / 2; j++) {
			A = str.substr(0, i);
			B = str.substr(i, j);
			if (A == B)continue;
			AB = A + B;
			temp = AB + AB + A;
			if (temp == str)return true;
		}
	}
	for (int i = 1; i < len / 2; i++) {
		for (int j = 1; j < len / 2; j++) {
			A = str.substr(0, i);
			B = str.substr(i, j);
			if (A == B || 3 * (i + j) >= len)continue;
			int a = 2 * (i + j);
			int b = len - 3 * (i + j);
			C = str.substr(a, b);
			if (A == C || B == C)continue;
			AB = A + B;
			temp = AB + AB + C + AB;
			if (temp == str)return true;
		}
	}
	return false;
}
int main()
{
	string str;
	scanf("%d",&N);
	getchar();
	while (N--)
	{
		str = "";
		gets(c);
		int len = strlen(c);
		for (int i = 0; i < len; i++) {
			if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z')) {
				str += c[i];
			}
		}
		if (isPoetry(str)) {
			cout << "Yes"<<endl;
		}
		else cout << "No" << endl;
	}
}