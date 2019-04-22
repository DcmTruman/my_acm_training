#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1000005;
const int M = 46500;
const int INF = 999999999;
bool notprime[N];
int prime_1[M + 1], prime_2[N];
int num_1 = 0, num_2;
void Prime1()  // 第一次筛出46500以内的素数
{
    memset(notprime, false, sizeof(notprime));
    for(int i = 2; i <= M; i++)
        if(!notprime[i])
        {
            prime_1[num_1++] = i;
            for(int j = 2 * i; j <= M; j += i)
                notprime[j] = true;
        }
}
void Prime2(int l, int u)  // 第二次筛出给定范围内的素数
{
    memset(notprime, false, sizeof(notprime));
    num_2 = 0;
    if(l < 2)
        l = 2;
    int k = sqrt(u * 1.0);
    for(int i = 0; i < num_1 && prime_1[i] <= k; i++)
    {
        int t = l / prime_1[i];
        if(t * prime_1[i] < l)
            t++;
        if(t <= 1)
            t = 2;
        for(int j = t; (long long)j * prime_1[i] <= u; j++)  // 相乘会超范围，用long long
            notprime[j * prime_1[i] - l] = 1;
    }
    for(int i = 0; i <= u - l; i++)
        if(!notprime[i])
            prime_2[num_2++] = i + l;
}
int main()
{
    int l, u, dis, a_1, b_1, a_2, b_2, minn, maxx;;
    Prime1();
    while(scanf("%d%d", &l, &u) != EOF)
    {
        minn = INF, maxx = -1;
        Prime2(l, u);
        if(num_2  < 2)
        {
            printf("There are no adjacent primes.\n");
            continue;
        }
        for(int i = 1; i < num_2 && prime_2[i] <= u; i++)
        {
            dis = prime_2[i] - prime_2[i - 1];
            if(dis > maxx)
            {
                a_1 = prime_2[i - 1];
                a_2 = prime_2[i];
                maxx = dis;
            }
            if(dis < minn)
            {
                b_1 = prime_2[i-1];
                b_2 = prime_2[i];
                minn = dis;
            }
        }
        printf("%d,%d are closest, %d,%d are most distant.\n", b_1, b_2, a_1, a_2);
    }
    return 0;
}