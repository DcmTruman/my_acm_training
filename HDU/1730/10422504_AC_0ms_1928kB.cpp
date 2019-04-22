#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int sum = 0;
        int a,b;
        while(n--)
        {
            cin>>a>>b;
            sum = sum^(abs(a-b)-1);
        }
        if(sum!=0)cout<<"I WIN!"<<endl;
        else cout<<"BAD LUCK!"<<endl;
    }
}