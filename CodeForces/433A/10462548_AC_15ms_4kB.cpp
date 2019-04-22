#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;

int n,num1 = 0,num2 = 0;
int main()
{
    ios::sync_with_stdio(false);
    int a;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>a;
        if(a == 100)num1++;
        else num2++;
    }
    if((num1&1)||((!num1)&&(num2&1)))cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
