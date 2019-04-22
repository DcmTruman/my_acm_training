#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    char s[222];
    while(gets(s),strcmp(s,"0"))
    {
        int len=strlen(s);
        stack<double>s1;
        stack<char>s2;
        for(int i=0;i<len;i++)
        {
            if(s[i]==' ')continue;
            else if(s[i]=='*'||s[i]=='/')
            {
                double x=s1.top();s1.pop();
                double y=0;
                int j;
                for(j=i+2;j<len;j++)
                {
                    if(s[j]!=' ')y=y*10+s[j]-'0';
                    else break;
                }
                if(s[i]=='*')s1.push(x*y);
                else s1.push(x/y);
                i=j;
            }
            else if(s[i]=='+'||s[i]=='-')s2.push(s[i]);
            else
            {
                double y=0;
                int j;
                for(j=i;j<len;j++)
                {
                    if(s[j]!=' ')y=y*10+s[j]-'0';
                    else break;
                }
                i=j;
                s1.push(y);
            }
        }
        stack<double>s3;
        stack<char>s4;
        while(!s1.empty())
        {
            s3.push(s1.top());
            s1.pop();
        }
        while(!s2.empty())
        {
            s4.push(s2.top());
            s2.pop();
        }
        while(!s4.empty())
        {
            double x=s3.top();s3.pop();
            double y=s3.top();s3.pop();
            char oo=s4.top();s4.pop();
            if(oo=='+')
                s3.push(x+y);
            else
                s3.push(x-y);
        }
        printf("%.2lf\n",s3.top());
    }
   
}