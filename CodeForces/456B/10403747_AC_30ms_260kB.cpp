#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int len = s.length();
    int temp;
    if(len == 1)
    {
        temp = s[0]-'0';
    }
    else
    {
        temp = (s[len-1]-'0') + 10*(s[len-2]-'0');
    }
    if(temp%4 == 0)cout<<"4"<<endl;
    else cout<<"0"<<endl;
    
}