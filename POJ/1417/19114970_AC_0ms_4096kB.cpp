#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define debug(x); cout << __LINE__ << ": name : " << #x << " "<<x<<endl;
using namespace std;

const int maxn = 1020;
int fa[maxn];
int val[maxn];
int cnt;
int n,p1,p2;
bool vis[maxn];
int id[maxn];
vector<int>ans;
struct St{
    int setasize,setbsize;
    vector<int> seta;
    vector<int> setb;
}st[maxn];

struct Dp{
    int pre;
    int val;
}dp[maxn][maxn];

void init(int n)
{
    cnt = 1;
    ans.clear();
    for(int i = 0;i<=n;i++){
        fa[i] = i;
        val[i] = 0;
        st[i].setasize = st[i].setbsize = 0;
        st[i].seta.clear();
        st[i].setb.clear();
        vis[i] = 0;
        for(int j = 0;j<=n;j++){
            dp[i][j].pre = dp[i][j].val = 0;
        }
    }
    dp[0][0].val = 1;
}

int find(int x)
{
    if(fa[x] == x)return fa[x];
    else{
        int f = find(fa[x]);
        val[x] = val[x] ^ val[fa[x]];
        fa[x] = f;
        return fa[x];
    }
}

void merge(int x,int y,int v)
{
    int xx = find(x);
    int yy = find(y);
    if(xx != yy){
        fa[xx] = yy;
        if(v)val[xx] = !(val[x] ^ val[y]);
        else val[xx] = val[x] ^ val[y];
    }
}




int main()
{
    char tmp[5];
    while(~scanf("%d%d%d",&n,&p1,&p2))
    {
        //并查集
        if(n == 0 && p1 == 0 && p2 == 0)break;
        init(p1+p2);
        for(int i = 0;i<n;i++){
            int u,v;
            scanf("%d%d%s" , &u,&v,tmp);
            if(tmp[0] == 'n'){
                merge(u,v,1);
            }else{
                merge(u,v,0);
            }
        }

        //得到集合
        for(int i = 1;i<=p1+p2;i++){
            int f = find(i);
            if(!vis[f]){
                vis[f] = 1;
                if(!val[i]){
                    st[cnt].setasize++;
                    st[cnt].seta.push_back(i);
                }else{
                    st[cnt].setbsize++;
                    st[cnt].setb.push_back(i);
                }
                id[i] = id[f] = cnt;
                cnt ++;
            }else{
                if(!val[i]){
                    st[id[f]].setasize++;
                    st[id[f]].seta.push_back(i);
                }else{
                    st[id[f]].setbsize++;
                    st[id[f]].setb.push_back(i);
                }
                id[i] = id[f];
            }
        }

        //背包
        for(int i = 1;i<cnt;i++){
            for(int j = 0;j<=p1;j++){
                if(j >= st[i].setasize && dp[i-1][j-st[i].setasize].val>0){
                    dp[i][j].val += dp[i-1][j-st[i].setasize].val;
                    dp[i][j].pre = j - st[i].setasize;
                }
                if(j >= st[i].setbsize && dp[i-1][j-st[i].setbsize].val>0){
                    dp[i][j].val += dp[i-1][j-st[i].setbsize].val;
                    dp[i][j].pre = j - st[i].setbsize;
                }
            }
        }

        //不唯一
        if(dp[cnt-1][p1].val != 1)
        {
            printf("no\n");
            continue;
        }
        for(int i = cnt-1 , j = p1;i>=1;j = dp[i][j].pre , i--)
        {
            int tmp = j -dp[i][j].pre;
            if(tmp == st[i].setasize){
                for(int k = 0;k<st[i].setasize;k++)ans.push_back(st[i].seta[k]);
            }else{
                for(int k = 0;k<st[i].setbsize;k++)ans.push_back(st[i].setb[k]);
            }
        }
        sort(ans.begin(),ans.end());
        int sz = ans.size();
        for(int i = 0;i<sz;i++)printf("%d\n" , ans[i]);
        printf("end\n");




    }



}


