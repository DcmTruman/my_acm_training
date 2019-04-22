
#include<string>
#include<stdio.h>
#include<cmath>
#include<string>
#include<algorithm>

typedef unsigned long long ll;
#define maxn 1010
int f[maxn*maxn];
int pos;
int mod(ll m,ll n,int k)
{
    int b=1;
    while(n>0)
    {
        if(n&1){
            b=(b*m)%k;
        }
        n=n>>1;
        m=(m*m)%k;
    }
    return b;
}
void init(ll m)
{
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    for(int i=2;i<=m*m+10;i++)
    {
        f[i] = (f[i-2]+f[i-1])% m;
        if(f[i] == 1&&f[i-1] == 0){
            pos = i-1;
            break;
        }
    }
}



//int mod(ll a,ll b,int m)
//{
//    int r = 1;
//    ll base = a;
//    while(b>0)
//    {
//        if(b&1)r = (r*base)%m;
//        base = (base*base)%m;
//        b >>= 1;
//    }
//    return r;
//}
int main()
{
    ll a,b;
    int m,n;
    scanf("%d",&n);
    while(n--)
    {
        //cin>>a>>b>>m;
        scanf("%llu%llu%d",&a,&b,&m);
        if(m==1||a==0)printf("0\n");
        else
        {
            init(m);
            int ans = mod(a%pos,b,pos);
            //cout<<f[ans]<<endl;
            printf("%d\n",f[ans]);
        }
        
    }
}