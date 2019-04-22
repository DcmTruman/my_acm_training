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
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 400020
# define maxm 20020


using namespace std;

bool _[maxn];
bool vis[maxn][2];
bool fi = true;
int n,m;
int ans;
struct node{
    int x,y,step;
    bool fi;
};
node st,ed,tmp;
bool isok(int x,int y){
    if(x<0||y<0||x>=n||y>=m||(x*m+y>=maxn)||(x*m+y<0))return false;
    return true;
}
int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};

void bfs()
{
   vis[st.x*m+st.y][(int)(_[st.x*m+st.y])] = true;
   st.step = 0;
   st.fi = true;
   queue<node> q;
   q.push(st);
   ww(!q.empty()){
       node now = q.front();
       q.pop();
       if(now.x == ed.x&&now.y == ed.y){
           ans = now.step;
           return;
       }
       rep(i,4){
           int xx = now.x+mx[i];
           int yy = now.y+my[i];
           if(now.fi){
               if(_[now.x*m+now.y]&&(i == 0||i == 2)) continue;
               if((!_[now.x*m+now.y])&&(i == 1||i == 3))continue;
               if(isok(xx,yy)&&!vis[xx*m+yy][(!_[xx*m+yy])]){
                  tmp.x = xx;
                  tmp.y = yy;
                  tmp.step = now.step+1;
                  tmp.fi = false;
                  vis[xx*m+yy][(!_[xx*m+yy])] = true;
                  q.push(tmp);
               }
           }
           else{
               if(_[now.x*m+now.y]&&(i == 1||i == 3)) continue;
               if((!_[now.x*m+now.y])&&(i == 0||i == 2))continue;
               if(isok(xx,yy)&&(!vis[xx*m+yy][(_[xx*m+yy])])){
                  tmp.x = xx;
                  tmp.y = yy;
                  tmp.step = now.step+1;
                  tmp.fi = true;
                  vis[xx*m+yy][(_[xx*m+yy])] = true;
                  q.push(tmp);
               }
           }
       }
   }
}
int main()
{
    wT(){
        fi = true;
        ans = -1;
        clr0(vis);
        scf("%d%d",&n,&m);
        rep(i,n){
            rep(j,m){
                cin>>_[i*m+j];
            }
        }
        cin>>st.x>>st.y>>ed.x>>ed.y;
        st.x--;st.y--;ed.x--;ed.y--;
        bfs();
        pc(ans); 
    }
    return 0;
}