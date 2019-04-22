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
# define sl(x) scanf("%lld",&(x))
# define pc(x) printf("%d\n",(x));
# define pl(x) printf("%lld\n",(x));
# define scf scanf
# define prf printf
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 200

using namespace std;
int a[maxn],b[maxn];
int main()
{
    char s[120];
    wT(){
        scf("%s",s);
        int mx1 = 0,mx2 = 0;
        int len = strlen(s);
        clr0(a);clr0(b);
        for(int i = 0;i<len;i+=2){
            a[s[i]-'a']++;
        } 
        rep(i,26){
            mx1 = max(mx1,a[i]);
        }
        for(int i = 1;i<len;i+=2){
            b[s[i]-'a']++;
        }
        rep(i,26){
            mx2 = max(mx2,b[i]);
        }
        pc(len-mx1-mx2);
    }
}