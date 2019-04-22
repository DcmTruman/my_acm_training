#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool Root[6010];
vector<vector<int>>V;
vector<vector<int>>dp;
int n,root,ans;
void dfs( int a )
{
    if(!V[a].size())return;
    for( int i = 0 ; i<V[a].size() ; i++)
    {
        dfs(V[a][i]);
        dp[a][0] += max(dp[V[a][i]][1],dp[V[a][i]][0]);
        dp[a][1] += dp[V[a][i]][0];
    }
}
int main()
{
    while(cin >> n)
    {
        dp.clear();
        V.clear();
    dp.resize(n+5);
    V.resize(n+5);
    for(int i =1; i<=n ; i++){
        int a;
        cin>>a;
        Root[i] = true;
        dp[i].push_back(0);
        dp[i].push_back(a);
    }
    int a,b;
    cin>>a>>b;
    while(a&&b)
    {
        V[b].push_back(a);
        Root[a] = false;
        cin >> a >> b;
    }
    for(int i = 1; i <= n ; i++){
        if(Root[i]){
            root = i;
            Root[i]=false;
            break;
        }
    }
    dfs(root);
    ans = max(dp[root][0],dp[root][1]);
    cout << ans << endl;
    }
return 0;
}