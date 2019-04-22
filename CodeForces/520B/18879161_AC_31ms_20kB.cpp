#include <stdio.h>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <stack>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	if(m < n){
		cout << n - m << endl;
	}
	else if(m == n)cout << "0" << endl;
	else
	{
		int cnt = 0;
		while(n < m)
		{
			if(m & 1){
				m++;
				cnt ++;
			}else{
				m /= 2;
				cnt ++;
			}
		}
		cout << n - m + cnt << endl;
	}
}
