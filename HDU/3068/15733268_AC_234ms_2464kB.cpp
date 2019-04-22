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
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 1000020

using namespace std;

char str[maxn],str2[maxn];
int p[maxn];
int len1,len2;
void init()
{
    //clr0(p);
    str2[0] = '$';
    str2[1] = '#';
    rep(i,len1){
        str2[i*2+2] = str[i];
        str2[i*2+3] = '#';
    }
    len2 = len1*2+2;
    str2[len2] = '*';
}

void manacher()
{
    int id = 0,mx = 0;
    repf(i,1,len2-1){
        //cout<<p[i]<<endl;
        if(mx>i)p[i] = min(p[2*id-i],mx-i);
        else p[i] = 1;
       // cout<<p[i];
        for(;str2[i+p[i]] == str2[i-p[i]];p[i]++);
        if(p[i]+i>mx){
            mx = p[i]+i;
            id = i;
        }

    }
}

int main()
{
    ww(scanf("%s",str)!=EOF){
        len1 = strlen(str);
        init();
        int ans = 0;
        manacher();
        rep(i,len2){
            ans = max(ans,p[i]);
        }
        pc(ans-1);
    }
}