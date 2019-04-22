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
# define lowbit(x) (x)&(-x)
# define ww(a) while(a)
# define sc(x) scanf("%d",&(x))
# define sl(x) scanf("%I64d",&(x))
# define pc(x) printf("%d\n",(x));
# define pl(x) printf("%I64d\n",(x));
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define scf scanf
# define prf printf
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck(x) cout<<"[Debug : "<<#x<<" "<<(x)<<']';


using namespace std;

const int maxn = 100020;

int ls[400*maxn],rs[400*maxn];
int ans[maxn],f[maxn],root[maxn];
vector<int>d[maxn];
int tot;

int fa;
void init()
{
    repf(i,1,100000){
        for(int j = i;j<=100000;j+=i){
            d[j].push_back(i);
        }
    }
}

void build(int &x,int s,int t,int pos)
{
    if(!x){x = ++tot;ls[x] = rs[x] = 0;}
    if(s == t)return;
    int mid = (s+t)/2;
    if(mid>=pos)build(ls[x],s,mid,pos);
    else build(rs[x],mid+1,t,pos);
}

int merge(int x,int y,int s,int t)
{
    if(!x||!y)return x^y;//合并的子树中有为空的
    if(s == t) {ans[fa] = max(ans[fa],s);return x;}//合并的节点中均存在该因数，更新最大因数
    int mid = (s+t)/2;
    ls[x] = merge(ls[x],ls[y],s,mid);
    rs[x] = merge(rs[x],rs[y],mid+1,t);
    return x;
}
int main()
{
    init();
    int n;
    ww(~sc(n)){
        clrf(ans);
        repf(i,2,n){
            sc(f[i]);
        }
        tot = 0;
        int tmp;
        repf(i,1,n){
            sc(tmp);
            root[i] = ++tot;
            ls[tot] = rs[tot] = 0;
            rep(j,d[tmp].size()){
                build(root[i],1,1e5,d[tmp][j]);
            }
        }
        repd(i,n,1){
            fa = f[i];
            root[fa] = merge(root[fa],root[i],1,1e5);
        }
        repf(i,1,n){
            pc(ans[i]);
        }
    }    
}