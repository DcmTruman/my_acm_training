#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include <stdio.h>
#include <time.h>
#include <map>
#include <vector>
using namespace std;

const int maxn = 10020;


vector<int>V[maxn];
vector<int>tmp;

int cnt,x,y,u,v,n,root;
int fa[maxn];
bool vis[maxn] , flag , flag2;
void init(int n)
{
    for(int i = 0;i<=n;i++){fa[i] = 0 ; V[i].clear() ; vis[i] = 0;}
    tmp.clear();
}



void dfs(int now)
{
    cnt ++;
    vis[now] = true;
    int sz = V[now].size();
    if(sz > 2){
        flag = false;
    }

    if(sz == 0)tmp.push_back(now);
    sort(V[now].begin() , V[now].end() );

    for(int i = 0;i<sz;i++)
    {
        int to = V[now][i];
        if(vis[to]){
            flag2 = false;
        }
        else{
            if(sz == 1 && V[now][0] >= now){
                tmp.push_back(now);
                dfs(to);
            }else if(i == 0){
                dfs(to);
                tmp.push_back(now);
            }else{
                dfs(to);
            }
        }
    }
}

bool check()
{
    for(int i = 0;i<n-1;i++){
        if(tmp[i+1] < tmp[i])return false;
    }
    return true;
}

void print(int now)
{
    int sz = V[now].size();
    printf("(%d",now);
    if(sz == 1 && V[now][0] <= now){
        print(V[now][0]);
        printf("()");
    }
    else if(sz == 1 && V[now][0] > now){
        printf("()");
        print(V[now][0]);
    }
    else if(sz == 0)printf("()()");
    else{
        print(V[now][0]);
        print(V[now][1]);
    }
    printf(")");
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        root = 0;
        scanf("%d" , &n);
        init(n);
        cnt = 0;
        flag = true;
        flag2 = true;
        for(int i = 0 ;i < n-1;i++){
            scanf("%d%d" , &u , &v);
            V[u].push_back(v);
            fa[v] = u;
        }
        for(int i = 1;i<=n;i++){
            if(!fa[i]){
                root = i;
                break;
            }
        }
        if(!root){
            printf("ERROR1\n");
            continue;
        }
        //cout << root << endl;
        dfs(root);

        if( cnt < n||(!flag2)){
            printf("ERROR1\n");
            continue;
        }
        else if(!flag){
            printf("ERROR2\n");
            continue;
        }else if(!check()){
            printf("ERROR3\n");
            continue;
        }
        else{
            print(root);
            printf("\n");
        }

    }
}
