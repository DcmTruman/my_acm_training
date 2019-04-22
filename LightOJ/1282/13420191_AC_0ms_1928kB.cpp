#include<set>  
#include<cmath>  
#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
#define LL long long  
  
using namespace std;  
  
  
const int maxn = 1e6;  
const int mod = 1000;  
  
LL qucikpower(LL x,int k)  
{  
    LL ans = 1;  
    while(k)  
    {  
        if(k & 1)  
            ans = ans*x%mod;  
        x = x*x%mod;  
        k /= 2;  
    }  
  
    return ans;  
}  
  
int main(void)  
{  
    int T,n,k;  
    scanf("%d",&T);  
    int cas = 1;  
    while(T--)  
    {  
        scanf("%d%d",&n,&k);  
        int len = k*log10(n) + 1;  
        double t = pow(10,1.0*k*log10(n)-len+1);  
        while(t < 100)  
            t*=10;  
        int x = t;  
        int y = qucikpower(n,k);  
        printf("Case %d: %d %03d\n",cas++,x,y);  
    }  
    return 0;  
}  