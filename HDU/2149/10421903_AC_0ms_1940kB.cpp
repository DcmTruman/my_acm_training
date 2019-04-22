#include<iostream>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n%(m+1))
        {
            if(n <= m)
            {
                for(int i=0;i<=m-n;i++)
                {
                    if(i==0)cout<<n+i;
                    else cout<<" "<<n+i;
                }
            }
            else
            {
                cout<<n%(m+1);
            }
            cout<<endl;
        }
        else
        {
            cout<<"none"<<endl;
        }
    }
}