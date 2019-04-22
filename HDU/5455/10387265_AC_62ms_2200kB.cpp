#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
#include<string>
using namespace std;
const int Max = 1e6+20;
int v[Max];
int main()
{
    int num,n,flag,f,l,fflag,i;
    string s;
    cin>>n;
    int temp = 1;
    while(n--)
    {
        cin>>s;
        int len = s.size();
        for( i=0;i<=len;i++)v[i]=0;
        flag = 1;
        f = l = -1;
        fflag = 0;
        for(int i=0;i<len;i++)
        {
            if(s[i]!='f'&&s[i]!='c')
            {
                flag = 0;
                break;
            }
            
            if(s[i]=='c')
            {
                v[i] = 1;
                l = i;
                if(fflag == 0)f=i;
                fflag++;
            }
        }
        if(flag == 0)
        {
            printf("Case #%d: -1\n", temp++);
            continue;
        }
        
        if(fflag == 0)
        {
            printf("Case #%d: %d\n", temp++, (len+1)/2);
            continue;
        }
        
        if(fflag > 0)
        {
            if(len-1-l+f < 2) flag = 0;
        }
        
        if(fflag > 0 && flag)
        {
            for(i = f+1; i <= l; i++)
            {
                if(v[i])
                {
                    if(i-f-1 < 2)
                        flag = 0;
                    f = i;
                }
                if(flag == 0)break;
            }
        }
        
        if(flag == 0) printf("Case #%d: -1\n", temp++);
        
        else printf("Case #%d: %d\n", temp++, fflag);

    }
}