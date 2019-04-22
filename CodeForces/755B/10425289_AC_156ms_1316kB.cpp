#include<iostream>
#include<string.h>
#include<stdio.h>
#include<set>
#include<math.h>
using namespace std;
set<string>S;
int main()
{
    int n,m,num = 0;
    string s;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(!S.count(s))
        {
            S.insert(s);
        }
        else{
            num++;
        }
    }
    for(int i=0;i<m;i++)
    {
        cin>>s;
        if(!S.count(s))
        {
            S.insert(s);
        }
        else{
            num++;
        }
    }
    n = n-num+num%2;
    m = m-num;
    if(n>m)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}