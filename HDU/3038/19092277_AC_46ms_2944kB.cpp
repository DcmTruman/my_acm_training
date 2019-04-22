#include <iostream>
#include <string.h>
#include <algorithm>
#define debug(x); cout << __LINE__ << ": name : " << #x << " "<<x<<endl;
using namespace std;

const int maxn = 200020;
int fa[maxn];
int val[maxn];
void init()
{
    for(int i = 0;i<maxn;i++){
        fa[i] = i;
        val[i] = 0;
    }
}

int find(int x)
{
    if(fa[x] == x)return fa[x];
    else{
        int f = find(fa[x]);
        val[x] += val[fa[x]];
        fa[x] = f;
        return fa[x];
    }
}



int main()
{

    int n;
    int m;
    while(~scanf("%d%d",&n,&m)){
        init();
        int ans = 0;
        for(int i = 0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(w < u - v + 1){
                ans ++;
                continue;
            }
            if(u>v)swap(u,v);
            v ++;
            int xx = find(u);
            int yy = find(v);
            //if(xx > yy)swap(xx,yy);
            if(xx == yy){
                if(val[u] == 0 ){
                    //debug(u);debug(v);
                    ans ++ ;
                    continue;
                }else if(val[u] - val[v] != w){
                    //debug(u);debug(v);debug(val[u]);debug(val[v]);
                    ans ++;
                    continue;
                }
            }else{
                //debug(u);debug(v);
                //debug(xx);debug(yy);
                if(xx > yy)
                {
                    int t = val[u] - val[v] - w;
                    //debug(xx);
                    //debug(t);
                    if(t <0){
                        ans ++;
                        continue;
                    }else{
                        fa[yy] = xx;
                        val[yy] = t;
                    }
                }else{
                    int t = w - val[u];
                    //debug(t);
                    if(t < 0){
                        ans ++ ;
                        continue;
                    }else{
                        fa[xx] = yy;
                        val[xx] = t + val[v];
                    }
                }

            }
        }
        printf("%d\n" , ans);
    }


}

/*

10 3
1 10 20
1 5 30
5 7 1

10 2
3 3 1
3 3 1

*/
