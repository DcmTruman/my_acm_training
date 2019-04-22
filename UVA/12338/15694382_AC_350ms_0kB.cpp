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
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define gcd(a,b) __gcd((a),(b))
# define maxn 100020

using namespace std;

typedef unsigned long long ull;

vector<ull>hashcode[maxn];
char str[maxn];
int strhash[maxn];

void gethash(int pos)
{
    int len = strlen(str);
    strhash[pos] = len;
    hashcode[pos].clear();
    hashcode[pos].push_back(0);
    repf(i,1,len)hashcode[pos].push_back(hashcode[pos][i-1]*233+str[i-1]);
}


int main()
{
    fuckio
    int T,N,Q,a,b,l,r,mid;
    Sc(T);
    repf(tt,1,T){
        printf("Case %d:\n",tt);
        Sc(N);
        repf(i,1,N){
            scanf("%s",str);
            gethash(i);
        }
        Sc(Q);
        W(Q--){
            scanf("%d%d",&a,&b);
            int len = min(strhash[a],strhash[b]);
            l = 0;r = len;
            W(l<r){
                mid = (l+r+1)/2;
                //fuck
                if(hashcode[a][mid] == hashcode[b][mid])l = mid;
                else r = mid-1;
            }
            printf("%d\n",l);
        }
    }
}