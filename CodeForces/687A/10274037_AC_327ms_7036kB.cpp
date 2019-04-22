#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>M;
vector<int>D;
bool Visit[100020];
int n,m,flag = 0;
void dfs(int a)
{
    Visit[a]=true;
    if(flag)return;
    if(!M[a].size())return;
    else if(D[a]==0)D[a] = 1;
    for(int i =0;i<M[a].size();i++){
        if(!Visit[M[a][i]]){
            if(D[a]==1)D[M[a][i]] = 2;
            else D[M[a][i]] = 1;
        }
        else {
            if(D[a] == D[M[a][i]]){flag = 1;break;}
        }
    }
    for(int i =0;i<M[a].size();i++){
        if(!Visit[M[a][i]]){
            dfs(M[a][i]);
        }
    }
    
}
int main()
{
    cin>>n>>m;
    M.resize(n+5);
    D.resize(n+5);
    for(int i=1;i<=n;i++)D[i] = 0;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    for(int i = 1;i<=n;i++)
    {
        if(!Visit[i])
        {
            dfs(i);
        }
    }
    if(flag)cout<<-1<<endl;
    else
    {
        int k1=0,k2=0;
        for(int i = 1;i<=n;i++){
            if(D[i] == 1){
                k1++;
            }
            else if(D[i]==2){
                k2++;
            }
        }
        int flag1=0,flag2 = 0;
        cout<<k1<<endl;
        for(int i = 1;i<=n;i++){
            if(D[i] == 1){
                if(!flag1){cout<<i;flag1 = 1;}
                else cout<<" "<<i;
            }
        }
        cout <<"\n"<<k2<<endl;
        for(int i = 1;i<=n;i++){
            if(D[i] == 2){
                if(!flag2){cout<<i;flag2 = 1;}
                else cout<<" "<<i;
            }
        }
    }
}