#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
long long sum1[100020],sum2[100020],add[100020],bdd[100020];
int n,q,a,b,c;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i =1;i <= n;i++)
    {
        cin>>add[i];
        bdd[i] = add[i];
        sum1[i] = sum1[i-1]+add[i];
    }
    sort(bdd+1,bdd+n+1);
    for(int i = 1;i <= n;i++)
    {
        sum2[i] = sum2[i-1]+bdd[i];
    }
    cin >> q;
    for(int i = 1;i <= q;i++)
    {
        cin>>a>>b>>c;
        if(a == 1)cout<<sum1[c]-sum1[b-1]<<endl;
        else cout<<sum2[c] - sum2[b-1] << endl;
    }
}
