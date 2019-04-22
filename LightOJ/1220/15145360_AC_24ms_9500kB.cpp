#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#define MAXN 1000100
#define LL long long
#define ll __int64
#define INF 0xfffffff
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
using namespace std;
int v[MAXN],prime[MAXN];
int k;
void isprime()
{
    int i,j;
    mem(v);
    v[1]=1;
    k=0;
    for(i=2;i<MAXN;i++)
    {
        if(v[i]==0)
        {
            prime[k++]=i;
            for(j=i*2;j<MAXN;j+=i)
            v[j]=1;
        }
    }
}
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    isprime();
    LL n;
    int t,i;
    int cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        int bz=0;
        if(n<0)
        n=-n,bz=1;
        int ans=0;
        for(i=0;prime[i]*prime[i]<=n&&i<k;i++)//就是这，因为表的限制，所以i不能大于等于k
        {
            if(n%prime[i]==0)
            {
                int cnt=0;
                while(n%prime[i]==0)
                {
                    cnt++;
                    n/=prime[i];
                }
                if(ans==0)
                ans=cnt;
                else
                ans=gcd(ans,cnt);
            }
            if(n==1)
            break;
        }
        if(n>1)
        ans=1;
        if(bz)
        {
            while(ans%2==0)
            ans/=2;
        }
        printf("Case %d: ",++cas);
        printf("%d\n",ans);
    }
    return 0;
}