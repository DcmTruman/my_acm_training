#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>V;
long long Sp[100010];
int n,m;
long long dp[100010];
int main()
{
    cin>>n>>m;
    long long ans = 0;
    V.resize(n+5);
    for(int i =0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)V[a].push_back(b);
        else V[b].push_back(a);
        Sp[a]++;
        Sp[b]++;
    }
    for(int i =1;i<=n;i++)
    {
        dp[i] = 1;
        for(int j =0;j<V[i].size();j++)
        {
            dp[i] = max(dp[V[i][j]]+1,dp[i]);
        }
        ans = (dp[i]*Sp[i]>ans)?dp[i]*Sp[i]:ans;
    }
    cout<<ans<<endl;
}
