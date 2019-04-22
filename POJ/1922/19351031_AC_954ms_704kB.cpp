#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 120;
int main()
{
	int n;
	while(cin >> n && n)
	{
		double ans = 100000000;
		double a,b;
		for(int i = 0;i<n;i++){
			cin >> a >> b;
			if(b < 0)continue;
			ans = min(ans , ceil(b + (4.5) /  (a / 3600)));
		}
		cout << ans << endl;
	}
}
