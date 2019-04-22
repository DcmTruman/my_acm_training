#include<stdio.h>  
#include<string.h>  
#include<math.h>  
#include<string.h>  
#include<stdlib.h>  
#include<algorithm>  
#include<iostream>  
#include<queue>  
#include<stack>  
  
using namespace std;  
  
const double EXP = 1e-9;  
typedef long long ll;  
const ll maxn =  3;  //确定矩阵大小  
const ll mod =   1e9+7;  //取余数用  
  
struct mat  
{  
    ll m[maxn][maxn];  
}unit;   //unit为单位矩阵  
  
mat matmul(mat a,mat b)  //俩矩阵相乘  
{  
    mat ans;  
    ll x,i,j,k;  
    for(i=0;i<maxn;i++)  
    {  
        for(j=0;j<maxn;j++)  
        {  
            x=0;  
            for(k=0;k<maxn;k++)  
            {  
                x+=(a.m[i][k]*b.m[k][j])%mod;  
            }  
            ans.m[i][j] = x%mod;  
        }  
    }  
    return ans;  
}  
  
void init_unit()   //初始化单位矩阵  
{  
    for(ll i=0;i<maxn;i++)  
        unit.m[i][i] = 1;  
    return ;  
}  
  
mat pow_mat(mat a,ll n)  //矩阵快速幂，求矩阵a的n次幂  
{  
    mat ans = unit;  //unit为幺元  
    while(n)  
    {  
        if(n&1)  
            ans=matmul(ans,a);  
        a = matmul(a,a);  
        n>>=1;  
    }  
    return ans;  
}  
  
int main()  
{  
    ll n,t;  
    init_unit();  
    scanf("%lld",&t);  
    while(t--)  
    {  
        scanf("%lld",&n);  
        if(n==2)  
            printf("3\n");  
        else if(n==3)  
            printf("4\n");  
        else if(n==4)  
            printf("6\n");  
        else  
        {  
            mat a,b;   //a为表达式矩阵，b为快速幂矩阵  
            b.m[0][0]=1,b.m[0][1]=1,b.m[0][2]=0;  
            b.m[1][0]=0,b.m[1][1]=0,b.m[1][2]=1;  
            b.m[2][0]=1,b.m[2][1]=0,b.m[2][2]=0;  
  
            a.m[0][0]=6, a.m[0][1]=4,a.m[0][2]=3;  
            b = pow_mat(b,n-4);  
            a = matmul(a,b);  
            printf("%lld\n",a.m[0][0]%mod);  
        }  
    }  
    return 0;  
} 