#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        int a;
        cin>>a;
        while(a!=0)
        {
            int now = a&255;
            if(now == 97)ans++;
            a = a>>8;
        }
    }
    cout<<ans<<endl;
}