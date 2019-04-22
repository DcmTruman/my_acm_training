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
# define W(a) while(a)
# define Sc(x) scanf("%d",&(x))
# define Sd(x) scanf("%I64d",&(x))
# define Lson(x) (x)<<1
# define Rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fucl:"<<__LINE__<<endl;
# define gcd(a,b) __gcd((a),(b))
# define maxn 720
using namespace std;

int n,m;
int T;

int s[1000100];
int p[10100];
int nexta[10100];

void getnxt(int P[])
{
    clr0(nexta);
    nexta[0] = -1;
    int i = -1,j = 0;
    W(j<m){
        if(i==-1||P[i]==P[j]){
            nexta[j+1] = i+1;
            i++;j++;
        }else {
            i = nexta[i];
        }
    }
}

int kmp(int s[],int t[])//t为模式串，s为原串
{
    getnxt(t);
    int res = -1;
    int i = 0,j =0 ;
    W(i<n&&j<m){
        if(j==-1||s[i] == t[j]){
            i++;j++;
        }else{
            j = nexta[j];
        }
    }
    if(j == m){
        res = i-j;//根据题目要求改变
    }
    return res;
}
int main()
{
    fuckio
    Sc(T);
    W(T--){
        scanf("%d%d",&n,&m);
        rep(i,n)Sc(s[i]);
        rep(i,m)Sc(p[i]);
        int res = kmp(s,p);
        if(res!=-1)res++;
        printf("%d\n",res);
    }
}
