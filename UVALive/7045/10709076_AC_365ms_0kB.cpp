#include<iostream>
#include<set>
using namespace std;
long long ans,A,B;
void FFF(long long A,long long B)
{
    if(A==0&&B==0)
    {
        ans += 1;
        return;
    }
    else if(A==0||B==0)
    {
        ans += 2;
        return;
    }
    else
    {
        if(A<B)
        {
            long long temp = A;
            A = B;
            B = temp;
        }
        if(A%B == 0)
        {
            ans += A/B+1;
            return;
        }
        else
        {
            ans += A/B;
            FFF(A%B,B);
        }
    }
}
int main()
{
    long long Case;
    cin>>Case;
    long long t = Case;
    while(Case--)
    {
        cin>>A>>B;
         ans = 0;
        FFF(A,B);
        cout<<"Case #"<<t-Case<<": "<<ans<<endl;
    }
}