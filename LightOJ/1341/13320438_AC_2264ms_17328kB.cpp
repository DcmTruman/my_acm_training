    #include <cstdio>  
    #include <cstring>  
    #include <cmath>  
    #include <iostream>  
    #include <algorithm>  
    using namespace std;  
    #define maxn 1000047  
    #define LL long long  
    LL p[maxn], prim[maxn];  
    int k = 0;  
    void find_prim()  
    {  
        k = 0;  
        for(LL i = 2; i <= maxn; i++)  
        {  
            if(!p[i])  
            {  
                prim[k++] = i;  
                for(LL j = i+i; j <= maxn; j+=i)  
                {  
                    p[j] = 1;  
                }  
            }  
        }  
    }  
    LL cont(LL a)  
    {  
        LL s = 1;  
        if(a == 0)  
        {  
            return 0;  
        }  
        LL tt = 0;  
        LL i = 0;  
        while(prim[i] < a && i < k)  
        {  
            tt = 0;  
            if(a%prim[i] == 0)  
            {  
                while(a%prim[i] == 0)  
                {  
                    a/=prim[i];  
                    tt++;  
                }  
            }  
            s *= tt+1;  
            i++;  
        }  
        if(a > 1)  
        {  
            s *= 1+1;//一次  
        }  
        return s;  
    }  
    int main()  
    {  
        LL a, b;  
        int t;  
        int cas = 0;  
        find_prim();  
        scanf("%d",&t);  
        while(t--)  
        {  
            scanf("%lld%lld",&a,&b);  
            int cnt = 0;  
            LL num = 0, ans;  
            if(b >= sqrt(a))  
                ans = 0;        // b大小限定  
            else  
            {  
                for(LL i = 1; i < b; i++) //暴力枚举[1, b]中a的约数  
                {  
                    if(a%i == 0)  
                    {  
                        cnt++;  
                    }  
                }  
                num = cont(a)/2;  
                ans = num - cnt;  
            }  
            printf("Case %d: %lld\n",++cas,ans);  
        }  
        return 0;  
    }  