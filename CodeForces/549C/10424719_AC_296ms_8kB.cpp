#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    int n,k,sum = 0,a;
    int n1=0,n2=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a&1)n1++;
        else n2++;
        sum += a;
    }
    if(n == k)
    {
        if(sum&1)cout<<"Stannis"<<endl;
        else cout<<"Daenerys"<<endl;
    }
    else if(n1<=(n-k)/2)cout<<"Daenerys"<<endl;
    else if(n2<=(n-k)/2)
    {
        if(k&1)cout<<"Stannis"<<endl;
        else cout<<"Daenerys"<<endl;
    }
    else {
        if((n-k)%2 == 1)cout<<"Stannis"<<endl;
        else cout<<"Daenerys"<<endl;
    }
    
}