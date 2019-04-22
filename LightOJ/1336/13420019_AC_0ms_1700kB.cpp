#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef long long int LL;
#define N 1001000
#define ESP 1e-8
#define INF 0x3f3f3f3f
#define memset(a,b) memset(a,b,sizeof(a))

int main()
{
    int T, t=1;
    scanf("%d", &T);
    while(T --)
    {
        LL n;
        scanf("%lld", &n);

        LL sum = n;
        sum -= (int)sqrt(n);
        sum -= (int)sqrt(n/2);

        printf("Case %d: %lld\n", t++, sum);
    }
    return 0;
}