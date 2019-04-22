#include<iostream>
#include<set>
using namespace std;
int main()
{
    long long Case,N,a;
    cin>>Case;
    long long t = Case;
    while(Case--)
    {
        cin>>N;
        int flag = 1;
        for(int i = 0;i<N;i++)
        {
            cin>>a;
            if(a%3 != 0)
            {
                flag = 0;
            }
        }
        if(flag)cout<<"Case #"<<t-Case<<": Yes\n";
        else cout<<"Case #"<<t-Case<<": No\n";
    }
}