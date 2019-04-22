#include<stdio.h>  
#include<iostream>
#include<algorithm>  
using namespace std;
int n, T, a[2005];
int main()
{
	int s, q, p, ma, x, y;
	while (scanf("%d %d", &n, &T) != EOF)
	{
		a[0] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n + 1);//从小到大排序，  
		s = lower_bound(a, a + n + 1, 0) - a;//找到点0  
		ma = 0;
		for (q = s; q >= 0; q--)//q是往左  
		{
			for (p = s; p <= n; p++)//p是往右  
			{
				x = -a[q], y = a[p];
				if (2 * x + y <= T&&p - q>ma) ma = p - q;//左右  
				if (2 * y + x <= T&&p - q>ma) ma = p - q;//右左  
			}
		}
		cout << ma << endl;
	}
	return 0;
}
