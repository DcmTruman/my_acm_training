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
# define maxn 1000200
using namespace std;

const int maxn_tot = 500020;

struct Aho{
    struct state{
        int nxt[26];
        int fail,cnt;
    }stable[maxn_tot];

    int size;
    queue<int>q;
    void init(){
        W(!q.empty())q.pop();
        rep(i,maxn_tot){
             clr0(stable[i].nxt);
             stable[i].fail = stable[i].cnt = 0;
        }
        size = 1;
    }

    void ins(char *s){
        int n = strlen(s);
        int now = 0;
        rep(i,n){
            char c = s[i];
            if(!stable[now].nxt[c-'a']){
                stable[now].nxt[c-'a'] = size++;
            }
            now = stable[now].nxt[c-'a'];
        }
        stable[now].cnt++;
    }

    void build(){
       stable[0].fail = -1;
       q.push(0);
       W(!q.empty()){
           int u = q.front();
           q.pop();
           rep(i,26){
               if(stable[u].nxt[i]){
                   if(u == 0)stable[stable[u].nxt[i]].fail = 0;
                   else{
                       int v = stable[u].fail;
                       W(v!=-1){
                            if(stable[v].nxt[i]){
                                stable[stable[u].nxt[i]].fail = stable[v].nxt[i];
                                break;
                            }else{
                                v = stable[v].fail;
                            }
                       }
                       if(v == -1)stable[stable[u].nxt[i]].fail = 0;
                   }
                   q.push(stable[u].nxt[i]);
               }
           }
       }
    }

    int Get(int u){
        int res = 0;
        W(u){
           res += stable[u].cnt;
           stable[u].cnt = 0;
           u = stable[u].fail;
        }
        return res;
    }
    int match(char *s){
        int n = strlen(s);
        int res = 0,now = 0;
        rep(i,n){
            char c = s[i];
            if(stable[now].nxt[c - 'a']){
                now = stable[now].nxt[c - 'a'];
            }else {
                int p = stable[now].fail;
                W(p!=-1&&stable[p].nxt[c - 'a'] == 0)p = stable[p].fail;
                if(p == -1)now = 0;
                else now = stable[p].nxt[c-'a'];
            }
            if(stable[now].cnt){
                res += Get(now);
                //fuck
            }
        }
        return res;
    }
}aho;

int T,N;
char S[maxn];

int main()
{
    Sc(T);
    W(T--){
        aho.init();
        Sc(N);
        rep(i,N){
            scanf("%s",S);
            aho.ins(S);
        }
        aho.build();
        scanf("%s",S);
        printf("%d\n",aho.match(S));
    }
}




