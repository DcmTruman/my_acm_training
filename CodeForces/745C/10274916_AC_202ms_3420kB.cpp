#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>M;
vector<int>D;
bool Visit[1020];
int gov[1020] = {0,};
int n,m,k,num,flag,temp,x = 0,ans=0;
void dfs(int a)
{
    temp++;
    Visit[a] = true;
    if(gov[a])flag =a;
    if(!M[a].size())return;
    for(int i =0;i<M[a].size();i++){
        if(!Visit[M[a][i]]){
            dfs(M[a][i]);
        }
    }
}


int main()
{
    cin>>n>>m>>k;
    M.resize(n+5);
    for(int i =0 ;i<k;i++)
    {
        int a;
        cin>>a;
        gov[a] = 1;
    }
    for(int i =0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    for(int i =1;i<=n;i++)
    {
        if(!Visit[i]){
            flag = 0;
            temp = 0;
            dfs(i);
            if(flag)gov[flag] = temp;
            else x += temp;
        }
    }
    int max = 0,flag1 = 0;
    for(int i =1;i<=n;i++)
    {
        if(gov[i]>max)
        {
            max = gov[i];
            flag1 = i;
        }
    }
    gov[flag1] = gov[flag1]+x;
    for(int i =1;i<=n;i++)
    {
        if(gov[i])
        {
            ans += gov[i]*(gov[i]-1)/2;
        }
    }
    ans -= m;
    cout<<ans<<endl;
}
