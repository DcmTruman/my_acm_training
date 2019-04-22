# include <bits/stdc++.h>
# define INF 0x3f3f3f3f
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
# define pc(x) printf("%d\n",(x));
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 2020

using namespace std;

const int max_tot = 2020;
int dp[maxn][maxn];
int a[maxn];
int n;
struct Aho{

    int size = 1;
    queue<int>q;

    struct _node{
        int nxt[4];
        int cnt,fail;
    }node[max_tot];

    void init(){
        size = 1;
        while(!q.empty())q.pop();
        rep(i,max_tot){
            clrf(node[i].nxt);
            node[i].cnt= 0;
            node[i].fail = -1;
        }
    }

    int geti(char c){
        if (c == 'A') return 0;
        else if (c == 'C') return 1;
        else if (c == 'G') return 2;
        else if (c == 'T') return 3;
    }

    void ins(char *s){
        int n = strlen(s);
        int now = 0;
        rep(i,n){
            int c = geti(s[i]);
            if(node[now].nxt[c] == -1)node[now].nxt[c] = size++;
            now = node[now].nxt[c];
        }
        node[now].cnt++;
    }

    void build(){
        node[0].fail = -1;
        q.push(0);
        ww(!q.empty()){
            int u = q.front();
            q.pop();
            rep(i,4){
                if(node[u].nxt[i]!=-1){
                    if(u == 0)node[node[u].nxt[i]].fail = 0;
                    else{
                        int v = node[u].fail;
                        ww(v!=-1){
                            if(node[v].nxt[i]!=-1){
                                node[node[u].nxt[i]].fail = node[v].nxt[i];
                                int x = node[v].nxt[i];
                                if(node[x].cnt)node[node[u].nxt[i]].cnt = 1;
                                break;
                            }else{
                                v = node[v].fail;
                            }
                        }
                        if(v == -1)node[node[u].nxt[i]].fail = 0;
                    }
                    q.push(node[u].nxt[i]);
                }
                else{
                    if(u == 0)node[u].nxt[i] = 0;
                    else{
                        int x = node[u].fail;
                        node[u].nxt[i] = node[x].nxt[i];
                    }
                }
            }
        }
    }


    int fid(char *s){
        int n = strlen(s);
        int res = 0;
        int now = 0;
        rep(i,n){
            int c = geti(s[i]);
            if(node[now].nxt[c]){
                now = node[now].nxt[c];
            }else{
                int p = node[now].fail;
                ww(p!=-1&&node[p].nxt[c] == 0)p = node[p].fail;
                if(p == -1)now = 0;
                else now = node[p].nxt[c];
            }
            if(node[now].cnt){
                //res += Get(now);
            }
        }
        return res;
    }

    int DP(){
        repf(i,0,n){
            repf(j,0,size){
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        rep(i,n){
            rep(j,size){
                if(dp[i][j] == INF)continue;
                rep(k,4){
                    int x = node[j].nxt[k];
                    if(node[x].cnt)continue;
                    dp[i+1][x] = min(dp[i+1][x],dp[i][j]+(a[i+1]!=k));
                }
            }
        }
        int ans = INF;
        rep(i,size)ans = min(ans,dp[n][i]);
        if(ans == INF)return -1;
        return ans;
    }

}aho;

char str[maxn];

int main()
{
    int tt = 0;
    ww(sc(n)!=EOF&&n){
        tt++;
        aho.init();
        rep(i,n){
            scanf("%s",str);
            aho.ins(str);
        }
        aho.build();
        scanf("%s",str+1);
        n = strlen(str+1);
        repf(i,1,n)a[i] = aho.geti(str[i]);
        printf("Case %d: %d\n", tt, aho.DP());
    }
}