# include <bits/stdc++.h>
# define INF 0x3f3f3f3f
# define clr0(x) memset(x,0,sizeof(x))
# define clr1(x) memset(x,INF,sizeof(x))
# define rep(i,a) for(int i = 0;i<(a);i++)
# define repf(i,a,b) for(int i = (a);i<=(b);i++)
# define repu(i,a,b) for(int i = (a);i<(b);i++)
# define repd(i,a,b) for(int i = (a);i>=(b);i--)
# define lowbit x&(-x)
# define ww(a) while(a)
# define sc(x) scanf("%d",&(x))
# define pc(x) printf("%d\n",(x));
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 1000020

using namespace std;

int str[maxn],str2[maxn];
int p[maxn];
int len1,len2;
void init()
{
    //clr0(p);
    str2[0] = 300;
    str2[1] = 301;
    rep(i,len1){
        str2[i*2+2] = str[i];
        str2[i*2+3] = 301;
    }
    len2 = len1*2+2;
    str2[len2] = 302;
}

void manacher()
{
    int id = 0,mx = 0;
    repf(i,1,len2-1){
        //cout<<p[i]<<endl;
        if(mx>i)p[i] = min(p[2*id-i],mx-i);
        else p[i] = 1;
       // cout<<p[i];
        ww(str2[i-p[i]] == str2[i+p[i]]&&str2[i-p[i]]<=str2[i-p[i]+2])p[i]++;
        if(p[i]+i>mx){
            mx = p[i]+i;
            id = i;
        }

    }
}

int main()
{
    wT(){
        sc(len1);
        rep(i,len1)sc(str[i]);
        init();
        manacher();
        int ans = 0;
        rep(i,len2){
            ans = max(ans,p[i]);
        }
        pc(ans-1);
    }
}