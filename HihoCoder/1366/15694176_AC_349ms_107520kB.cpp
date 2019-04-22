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

const int ALTN = 30;
struct Node
{
    int flag;
    Node *nxt[ALTN];
    Node(){
        flag = 0;
        rep(i,ALTN)nxt[i] = NULL;
    }
};
Node *root;
void init()
{
    root = new Node();
}

void ins(char *s)
{
    int len = strlen(s);
    Node *now = root;
    repd(i,len-1,0){
        int to = s[i]-'a';
        if(now->nxt[to] == NULL)now->nxt[to] = new Node();
        now = now->nxt[to];
    }
    now->flag++;
}

int fid(char *s)
{
    int len = strlen(s);
    Node *now = root;
    rep(i,len){
        int to = s[i]-'a';
        if(now->nxt[to] == NULL)return 0;
        now = now->nxt[to];
    }
    return now->flag;
}


int main()
{
    fuckio
    int n;Sc(n);
    int ans = 0;
    char s[30];
    init();
    W(n--){
        scanf("%s",s);
        ans += fid(s);
        ins(s);
        clr0(s);
    }
    printf("%d\n",ans);
}