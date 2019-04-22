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
        stack<double>num;//存储整数 
        stack<char>op;//存储运算符 
        for(int i=0;i<len;i++)
        {
            if(s[i]==' ')//空格直接跳过 
                continue;
            else if(s[i]=='*'||s[i]=='/')//乘除法,运算完后将结果进栈 
            {
                double x=num.top();//拿出数字栈中的栈顶元素 
                num.pop();
                double y=0;
                int j;
                for(j=i+2;j<len;j++)//提取出字符串中的整数 
                {
                    if(s[j]!=' ')
                        y=y*10+s[j]-'0';
                    else
                        break;
                }
                //将结果进栈 
                if(s[i]=='*')
                    num.push(x*y);
                else
                    num.push(x/y);
                i=j;
            }
            else if(s[i]=='+'||s[i]=='-')//加减法,直接进栈 
                op.push(s[i]);
            else//数字则提取出来进栈 
            {
                double y=0;
                int j;
                for(j=i;j<len;j++)
                {
                    if(s[j]!=' ')
                        y=y*10+s[j]-'0';
                    else
                        break;
                }
                i=j;
                num.push(y);
            }
        }
        //因为进栈之后出栈顺序与运算顺序相反,所以要将栈内元素反转 
        stack<double>nnum;
        stack<char>oop;
        while(!num.empty())
        {
            double temp=num.top();
            nnum.push(temp);
            num.pop();
        }
        while(!op.empty())
        {
            char temp=op.top();
            oop.push(temp);
            op.pop();
        }
        while(!nnum.empty()&&!oop.empty())
        {
            double x=nnum.top();//拿出第一个整数 
            nnum.pop();
            double y=nnum.top();//拿出第二个整数 
            nnum.pop();
            char ope=oop.top();//拿出运算符 
            oop.pop();
            //将结果进栈 
            if(ope=='+')
                nnum.push(x+y);
            else
                nnum.push(x-y);
        }
        printf("%.2lf\n",nnum.top());
    }
    return 0;
}