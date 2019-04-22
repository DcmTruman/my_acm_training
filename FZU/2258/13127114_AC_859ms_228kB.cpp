#include<iostream>

using namespace std;

int main()
{
    int N;
    int a,b,c;
    int ans = 0;
    while(~scanf("%d",&N))
    {
        ans = 0;
        for(int i = 0;i<N;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a>=60&&b>=60&&c>=60&&(a+b+c)>=240)ans++;
            
        }
        printf("%d\n",ans);
    }
}