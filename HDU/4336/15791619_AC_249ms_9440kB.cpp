    #include <cstdio>
    #include <cstring>
    #define _cle(m, a) memset(m, a, sizeof(m))
    #define N (1<<20)
    double dp[N + 1];
    double p[25];
    int main()
    {
        int n;
        double t;
        while(~scanf("%d", &n))
        {
            _cle(dp, 0);
            for(int i = 0; i < n; i++)
                scanf("%lf", &p[i]);
            for(int i = (1<<n) - 2; i >= 0; i--)
            {
                t = 0.0;
                dp[i] ++;
                for(int j = 0; j < n; j++)
                    if(!(i & (1<<j)))
                    {
                        dp[i] += dp[i | (1<<j)] * p[j];
                        t += p[j];
                    }
                dp[i] /= t;
            }
            printf("%.4lf\n", dp[0]);
        }
    }
