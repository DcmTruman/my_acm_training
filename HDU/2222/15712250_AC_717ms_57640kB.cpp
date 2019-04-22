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

const int max_tot = 500020;
struct Aho{

    int size = 1;
    queue<int>q;

    struct _node{
        int nxt[26];
        int cnt,fail;
    }node[max_tot];

    void init(){
        size = 1;
        while(!q.empty())q.pop();
        rep(i,max_tot){
            clr0(node[i].nxt);
            node[i].cnt = node[i].fail = 0;
        }
    }

    void ins(char *s){
        int n = strlen(s);
        int now = 0;
        rep(i,n){
            char c = s[i];
            if(!node[now].nxt[c-'a'])node[now].nxt[c-'a'] = size++;
            now = node[now].nxt[c-'a'];
        }
        node[now].cnt++;
    }

    void build(){
        node[0].fail = -1;
        q.push(0);
        W(!q.empty()){
            int u = q.front();
            q.pop();
            rep(i,26){
                if(node[u].nxt[i]){
                    if(u == 0)node[node[u].nxt[i]].fail = 0;
                    else{
                        int v = node[u].fail;
                        W(v!=-1){
                            if(node[v].nxt[i]){
                                node[node[u].nxt[i]].fail = node[v].nxt[i];
                                break;
                            }else{
                                v = node[v].fail;
                            }
                        }
                        if(v == -1)node[node[u].nxt[i]].fail = 0;
                    }
                    q.push(node[u].nxt[i]);
                }
            }
        }
    }

    int Get(int u){
        int res = 0;
        W(u){
            res += node[u].cnt;
            node[u].cnt = 0;
            u = node[u].fail;
        }
        return res;
    }
    int fid(char *s){
        int n = strlen(s);
        int res = 0;
        int now = 0;
        rep(i,n){
            char c = s[i];
            if(node[now].nxt[c-'a']){
                now = node[now].nxt[c - 'a'];
            }else{
                int p = node[now].fail;
                W(p!=-1&&node[p].nxt[c-'a'] == 0)p = node[p].fail;
                if(p == -1)now = 0;
                else now = node[p].nxt[c-'a'];
            }
            if(node[now].cnt){
                res += Get(now);
            }
        }
        return res;
    }

}aho;

char S[maxn];

int main()
{
    int T,N;
    Sc(T);
    W(T--){
        Sc(N);
        aho.init();
        rep(i,N){
            scanf("%s",S);
            aho.ins(S);
        }
        aho.build();
        scanf("%s",S);
        printf("%d\n",aho.fid(S));
    }
}