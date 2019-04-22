#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>                                                                                                                                         # include <queue>
#include <vector>
#include <map>
#include <stack>
#include <functional>
#include <math.h>
#include <set>
#include <time.h>
#define debug(x) cout<<" [ Debug : "<<#x<<" = "<<x<<" ]\n"
#define INF 0x3f3f3f3f
#define Inf 0x7f7f7f7f
#define clr0(x) memset(x,0,sizeof(x))
#define clr1(x) memset(x,INF,sizeof(x))
#define clrf(x) memset(x,-1,sizeof(x))
#define rep(i,a) for(int i = 0;i<(a);i++)
#define repf(i,a,b) for(int i = (a);i<=(b);i++)
#define repu(i,a,b) for(int i = (a);i<(b);i++)
#define repd(i,a,b) for(int i = (a);i>=(b);i--)
#define lowbit x&(-x)
#define ww(a) while(a)
#define sc(x) scanf("%d",&(x))
#define sl(x) scanf("%I64d",&(x))
#define pc(x) printf("%d\n",(x));
#define pl(x) printf("%I64d\n",(x));
#define wT() int T;scanf("%d",&T);while(T--)
#define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
#define lson(x) (x)<<1
#define rson(x) (x)<<1|1
#define ll long long
#define scf scanf
#define prf printf
#define fuckio ios::sync_with_stdio(false);
#define fuck cout<<"fuck:"<<__LINE__<<endl;
#define Sz(x) (int)(x).size()
#define pb push_back
#define maxn (int)200
#define maxm (int)2220000
using namespace std;

map<int,int>M;
bool _g[maxn*maxn][maxn*maxn];
char _m[maxn][maxn];
int _[maxn][maxn];
int mmx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
int num;
int n,m;
int dp[maxn],stk[maxn][maxn],mx;
void init()
{
    num = 0;
    rep(i,n*m){
    	rep(j,n*m){
    		_g[i][j] = true;
		}
	}
    M.clear();
}
bool isOK(int x,int y)
{
    if(x<0||y<0||x>=n||y>=m)return false;
    return true;
}

int dfs(int n,int ns,int dep)
{
    if(0 == ns){
        if(dep>mx)mx = dep;
        return 1;
    }
    int i,j,k,p,cnt;
    for(int i = 0;i<ns;i++){
        k = stk[dep][i];cnt = 0;
        if(dep+n-k<=mx)return 0;
        if(dep+dp[k]<=mx)return 0;
        for(int j = i+1;j<ns;j++){
            p = stk[dep][j];
            if(_g[k][p])stk[dep+1][cnt++] = p;
        }
        dfs(n,cnt,dep+1);
    }
}

int clique(int n)
{
    int i,j,ns;
    for(mx = 0,i = n-1;i>=0;i--){
        for(ns = 0,j = i+1;j<n;j++){
            if(_g[i][j])stk[1][ns++] = j;
        }
        dfs(n,ns,1);dp[i] = mx;
    }
    return mx;
}
int main()
{
    wt(){
        //init();
        scf("%d%d",&n,&m);
        init();
        rep(i,n){
            rep(j,m){
            	cin >> _m[i][j];
                //scf("%c",&_m[i][j]);
            }
            //getchar();
        }
        //fuck
        rep(i,n){
            rep(j,m){
                if(_m[i][j] == '.'){
                    _[i][j] = num ++;
                }else{
                    int tmp = _m[i][j] - '0';
                    if(!M.count(tmp)){
                        M[tmp] = num++;
                    }
                    _[i][j] = M[tmp];
                }
            }
        }
        rep(i,n){
            rep(j,m){
                rep(k,4){
                    int xx = i + mmx[k];
                    int yy = j + my[k];
                    if(isOK(xx,yy)){
                        if(_[xx][yy]!=_[i][j]){
                            _g[_[xx][yy]][_[i][j]] = false;
                            _g[_[i][j]][_[xx][yy]] = false;
                        }
                    }
                }
            }
        }
//        rep(i,n){
//        	rep(j,m){
//        		cout << _[i][j];
//			}
//			cout << endl;
//		}
//		cout << "--------"<<endl;
//		rep(i,num){
//			rep(j,num){
//				if(_g[i][j])cout<<"1";
//				else cout <<"0";
//			}
//			cout << endl;
//		}
        prf("Case #%d: %d\n",tt,clique(num));


    }
    //system("pause");
}