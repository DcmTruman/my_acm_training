#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int NDD[2200] = { 0, };
int N, ans = 0;
long long T;
int main()
{
	while (scanf("%d %d", &N, &T) != EOF)
	{
		NDD[0] = 0;
		ans = 0;
		int p = 0;
		for (int i = 1; i <= N; i++) {
			int a;
			cin >> a;
			NDD[i] = a;
		}
		sort(NDD, NDD + N + 1);
		for (int i = 1; i < N; i++) {
			if (NDD[i] == 0) {
				p = i;
				break;
			}
		}
		for (int i = p; i >= 0; i--) {
			for (int j = p; j <= N; j++) {
				int x = -NDD[i];
				int y = NDD[j];
				if (2 * x + y <= T&&j - i > ans)ans = j - i;
				if (2 * y + x <= T&&j - i > ans)ans = j - i;
			}
		}
		cout << ans << endl;
	}
}
