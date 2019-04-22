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
bool _[maxn][maxn];
int n;
int main()
{
    wT(){
        sc(n);
        repf(i,0,n-1)repf(j,i+1,n-1)cin>>_[i][j],_[j][i] = _[i][j];
        bool flag1 = false,flag2 = false;
        repf(i,0,n-1){
            repf(j,i+1,n-1){
                repf(k,j+1,n-1){
                    if(_[i][j]&&_[j][k]&&_[i][k]){flag1 = true;break;}
                    if((!_[i][j])&&(!_[j][k])&&(!_[i][k])){flag2 = true;break;}
                }
                if(flag1||flag2)break;
            }
            if(flag1||flag2)break;
        } 
        prf((flag1||flag2)?"Bad Team!\n":"Great Team!\n");
    }
}