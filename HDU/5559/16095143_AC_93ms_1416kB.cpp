# include <iostream>
# include <string>
# include <string.h>
# include <algorithm>                                                                                                                                         # include <queue>
# include <vector>
# include <map>
# include <stack>
# include <functional>
# include <math.h>
# include <set>
# include <time.h>
# define debug(x) cout<<" [ Debug : "<<#x<<" = "<<x<<" ]\n"
# define INF 0x3f3f3f3f
# define Inf 0x7f7f7f7f
# define clr0(x) memset(x,0,sizeof(x))
# define clr1(x) memset(x,INF,sizeof(x))
# define clrf(x) memset(x,-1,sizeof(x))
# define rep(i,a) for(int i = 0;i<(a);i++)
# define repf(i,a,b) for(int i = (a);i<=(b);i++)
# define repu(i,a,b) for(int i = (a);i<(b);i++)
# define repd(i,a,b) for(int i = (a);i>=(b);i--)
# define lowbit x&(-x)
# define ww(a) while(a)
# define sc(x) scanf("%d",&(x))
# define sl(x) scanf("%I64d",&(x))
# define pc(x) printf("%d\n",(x));
# define pl(x) printf("%I64d\n",(x));
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define scf scanf
# define prf printf
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define Sz(x) (int)(x).size()
# define pb push_back
# define maxn (int)200000
# define maxm (int)2220000
using namespace std;


int n,m,k;
int main()
{
    wt(){
        scf("%d %d %d",&n,&m,&k);
        prf("Case #%d:\n",tt);
        if(m>n){
            prf("Impossible\n");
            continue;
        }
        else if(m == n){
            rep(i,n)prf("A");
            prf("\n");
            continue;
        }
        else if(n>m){
            if(k == 1){
                prf("Impossible\n");
                continue;
            }
            else if(k == 2){
                if(n == 8&&m == 7){
                    prf("AABBABAA\n");
                    continue;
                }
                else if(m<8){
                    prf("Impossible\n");
                    continue;
                }
                else{
                    for(int i = 0;i<m-8;i++)prf("A");
                    int cnt = 0;
                    string ttt = "ABAABB";
                    for(int i = m-7;i<=n;i++){
                        prf("%c",ttt[(cnt)%6]);
                        cnt++;
                        
                    }
                    prf("\n");
                }
            }
            else if(k >= 3){
                if(m<3){
                    prf("Impossible\n");
                    continue;
                }
                else{
                    for(int i = 0;i<m-3;i++)prf("A");
                    int cnt = 0;
                    string ttt = "ABC";
                    for(int i = m-2;i<=n;i++){
                        prf("%c",ttt[(cnt)%3]);
                        cnt ++;
                    }
                    prf("\n");
                }
            }
        }
    }
    //system("pause");
}