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
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 1000020


using namespace std;

bool isp[maxn];
int pr[maxn];
int line[70];
int cnt = 0;
int n,m;
void init()
{
    clr1(isp);
    repf(i,2,maxn-1){
        if(isp[i]){
            pr[cnt++] = i;
            for(int j = i+i;j<maxn;j+=i)isp[j] = false;
        }
    }
}


int main()
{
    fuckio
    init();
    wt(){
        clr0(line);
        scanf("%d%d",&n,&m);
        rep(i,n){
            rep(j,m){
                int tmp;sc(tmp);
                rep(k,cnt){
                    if(tmp == 1)break;
                    while(tmp%pr[k] == 0){
                        line[i]++;
                        tmp /= pr[k];
                    }
                }
                if(tmp!=1)line[i]++;
            }
        }
        int ans = 0;
        rep(i,n){
            ans ^= line[i];
        }
        if(ans)printf("Case #%d: YES\n",tt);
        else printf("Case #%d: NO\n",tt);

    }
}