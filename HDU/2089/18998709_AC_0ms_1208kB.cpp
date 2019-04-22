#include<stdio.h>
#include<string.h>
using namespace std;
int dp[10][10];
int digit[10];
void init()
{
    //十位加个位dp，百位加十位dp，千位加百位dp
    dp[0][0]=1;
    for(int i=1;i<=7;i++)
    {
        for(int j=0;j<10;j++)//枚举第i位数上的数字、
        {
            for(int k=0;k<10;k++)//枚举第i-1位上的数字、
            {
                if(!(j==6&&k==2)&&j!=4)//满足条件
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
}
int calchangdu(int n)
{
    int cont=0;
    while(n)
    {
        cont++;
        n/=10;
    }
    return cont;
}
int caldigit(int n,int len)
{
    memset(digit,0,sizeof(digit));
    for(int i=1;i<=len;i++)
    {
        digit[i]=n%10;
        n/=10;
    }
}
int solve(int n)//计算[0,n)符合条件的个数
{
     int ans=0;
     int len=calchangdu(n);
     caldigit(n,len);
     for(int i=len;i>=1;i--)//从最高位开始枚举
     {
         for(int j=0;j<digit[i];j++)
         {
             if(!(j==2&&digit[i+1]==6)&&j!=4)
             {
                 ans+=dp[i][j];
             }
         }
        if(digit[i]==4 || (digit[i]==2 && digit[i+1]==6))//第i位已经不满足条件，则i位以后都不可能满足条件，结束循环
            break ;
     }
     return ans;
}
int main()
{
    init();
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)break;
        printf("%d\n",solve(m+1)-solve(n));
    }
}
