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

int n;
int main()
{
    ww(~sc(n)){
        if(n<4){prf("NO\n");continue;}
        prf("YES\n");
        if(n&1){
            prf("5 * 3 = 15\n");
            prf("2 * 4 = 8\n");
            prf("15 + 8 = 23\n");
            prf("23 + 1 = 24\n");
            for(int i = n;i>5;i-=2){
                prf("%d - %d = 1\n",i,i-1);
                prf("24 * 1 = 24\n");
            }
        }
        else{
            prf("1 + 2 = 3\n");
            prf("3 + 3 = 6\n");
            prf("4 * 6 = 24\n");
            for(int i = n;i>4;i-=2){
                prf("%d - %d = 1\n",i,i-1);
                prf("24 * 1 = 24\n");
            }
        }
    }
}