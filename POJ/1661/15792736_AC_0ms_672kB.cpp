# include <iostream>
# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <math.h>
# include <queue>
# include <string>
# include <vector>
# include <set>
# include <map>
# define INF 0x3f3f3f3f
# define Inf 0x7f7f7f7f
# define _sz(x) (x).size()
# define qisok(q) (!(q).empty())
# define clr0(x) memset(x,0,sizeof(x))
# define clr1(x) memset(x,INF,sizeof(x))
# define clrf(x) memset(x,-1,sizeof(x))
# define rep(i,a) for(int i = 0;i<(a);i++)
# define repf(i,a,b) for(int i = (a);i<=(b);i++)
# define repu(i,a,b) for(int i = (a);i<(b);i++)
# define repd(i,a,b) for(int i = (a);i>=(b);i--)
# define lowbit(x) ((x)&(-x))
# define ww(a) while(a)
# define sc(x) scanf("%d",&(x))
# define sl(x) scanf("%I64d",&(x))
# define pc(x) printf("%d\n",(x));
# define pl(x) printf("%I64d\n",(x));
# define scf scanf
# define prf printf
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 3020


using namespace std;

int N,X,Y,MAX;
struct pl{
    int x1,x2,h;
};
bool cmp (pl a,pl b)
{
    return a.h<b.h;
}
int dp[maxn][2];
pl plat[maxn];
int k;
int main()
{
    wT(){
        bool flag;
        clr0(dp);
        scf("%d%d%d%d",&N,&X,&Y,&MAX);
        plat[0].x1 = -20000,plat[0].x2 = 20000, plat[0].h = 0; 
        repf(i,1,N){
            scf("%d%d%d",&plat[i].x1,&plat[i].x2,&plat[i].h);
        } 
        plat[N+1].x1 = X,plat[N+1].x2 = X,plat[N+1].h = Y;
        sort(plat,plat+N+1,cmp);
        repf(i,1,N+1){
            k = i-1;
            flag = false;
            ww(k>0&&plat[i].h-plat[k].h<=MAX){
                if(plat[k].x1<=plat[i].x1&&plat[k].x2>=plat[i].x1){
                    dp[i][0] = plat[i].h-plat[k].h+min(plat[i].x1-plat[k].x1+dp[k][0],plat[k].x2-plat[i].x1+dp[k][1]);
                    flag = true;
                    break;
                }
                else k--;
            }
            if(plat[i].h-plat[k].h>MAX&&!flag)dp[i][0] = INF;
            else if(!flag)dp[i][0] = plat[i].h;
            k = i-1;
            flag = false;
            ww(k>0&&plat[i].h-plat[k].h<=MAX){
                if(plat[k].x1<=plat[i].x2&&plat[k].x2>=plat[i].x2){
                    dp[i][1] = plat[i].h-plat[k].h+min(plat[i].x2-plat[k].x1+dp[k][0],plat[k].x2-plat[i].x2+dp[k][1]);
                    flag = true;
                    break;
                }
                else k--;
            }
            if(plat[i].h-plat[k].h>MAX&&!flag)dp[i][1] = INF;
            else if(!flag)dp[i][1] = plat[i].h;
        }
        pc(min(dp[N+1][0],dp[N+1][1]));
    }
}