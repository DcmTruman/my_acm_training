#include <iostream>
#include <stdio.h>

#define ll long long
using namespace std;
int n;
ll ans[30];

long long qpow(long long a, long long b)
{
    long long res=1;
    while(b>0)
    {
        if(b&1)res=res*a;
        b=b>>1;
        a=a*a;
    }
    return res;
}
void solve()
{
	
	//temp数组用来记录以某一位为结尾的方案书，其中1和6等价，2，3，4，5等价
	ll temp[2];

	ans[3] = 104ll;
	ll last_t = 16;
	for(int i = 4;i<=25;i++){
		//先考虑上一个递推答案满足条件的情况
		//如果上一个以满足条件，那么当前位填2345都行，如果填1，需要减去上次填6的个数（用last_t记录）
		temp[0] = ans[i-1] - last_t;
		temp[1] = ans[i-1];

		//如果不满足
		//如果当前选2，3，4，5
		//C(5,2) - 1 = 9
		temp[1] += 9 * (qpow(2, i-1) - 2);
		//如果当前选1
		//如果之前选6
		//C(4 , 1) * (qpow(2 , i-2) - 1)	
		temp[0] += 4 * (qpow(2 , i-2) - 1);
		//如果之前不选6
		//C(4 , 2) * (qpow(2 , i-1) - 2)
		temp[0] += 6 * (qpow(2 , i-1) - 2);

		//记录上一次
		last_t = temp[0];
		ans[i] = 2 * temp[0] + 4 * temp[1];
	}
}
int main()
{
	solve();
	for(int i = 3;i<=25;i++)
	{
		printf("N=%d: %lld\n" , i , ans[i]);
	}
}
