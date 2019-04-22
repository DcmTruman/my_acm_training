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
# define sd(x) scanf("%I64d",&(x))
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define gcd(a,b) __gcd((a),(b))
# define maxn 120
using namespace std;


int fa[maxn];
int xx[maxn];
int yy[maxn];
int n,m,cnt,num;
void init()
{
    repf(i,0,n)fa[i] = i;
    cnt = 0;
    num = 0;
}

int find(int x)
{
    return (fa[x] == x)?x:fa[x] = find(fa[x]);
}

struct edge
{
    int u;
    int v;
    double len;
}E[maxn*maxn];

bool cmp(edge a,edge b)
{
    return a.len<b.len;
}


double kruskal()
{
    double ret = 0;
    rep(i,cnt){
        int fu = find(E[i].u);
        int fv = find(E[i].v);
        if(fu!=fv){
            fa[fu] = fv;            
            ret += E[i].len;
            num ++;
        }
    }
    return ret;
}
int main()
{
    int T;sc(T);
    ww(T--){
        sc(n);
        init();
        repf(i,1,n){
            scanf("%d%d",&xx[i],&yy[i]);
        }
        repf(i,1,n){
            repf(j,1,n){
                double tmp =sqrt((xx[i]-xx[j])*(xx[i]-xx[j])+(yy[i]-yy[j])*(yy[i]-yy[j]));
                if(tmp>=10&&tmp<=1000){
                    E[cnt].u = i;
                    E[cnt].v = j;
                    E[cnt++].len = tmp;       
                }
            }
        }
        sort(E,E+cnt,cmp);
        double ans = kruskal()*100;
        if(num!=n-1)printf("oh!\n");
        else printf("%.1lf\n",ans);
    }
}