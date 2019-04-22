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
# define rep(i,a) for(int i = 0;i<(a);i++)
# define repf(i,a,b) for(int i = (a);i<=(b);i++)
# define repu(i,a,b) for(int i = (a);i<(b);i++)
# define repd(i,a,b) for(int i = (a);i>=(b);i--)
# define lowbit x&(-x)
# define W(a) while(a)
# define Sc(x) scanf("%d",&(x))
# define Lson(x) (x)<<1
# define Rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 200020

using namespace std;

struct Node{
    int flag;
    Node *nxt[2];
    Node(){
        rep(i,2)nxt[i] = NULL;
        flag = 0;
    }
};
Node *root;
void init()
{
    root = new Node();
}
void ins(int s)
{
    Node *now = root;
    int len = 32;
    repd(i,len-1,0){
        int to = (s>>i)&1;
        //cout<<to<<" ";
        if(now->nxt[to] == NULL)now->nxt[to] = new Node();
        now = now->nxt[to];
    }
    now->flag = s;
}

int fid(int s)
{
    Node *now = root;
    int len = 32;
    
    repd(i,len-1,0){
        int to =  (s>>i)&1;
        
        if(now->nxt[to^1] != NULL){
        	//cout<<(to+1)%2<<" ";
            now = now->nxt[to^1];
        }else {
        	//cout<<to<<" ";
            now = now->nxt[to];
        }
    }
    return now->flag;
}


int main()
{
    fuckio
    int T;Sc(T);
    int n,m;
    repf(tt,1,T){
        printf("Case #%d:\n",tt);
        init();
        Sc(n);Sc(m);
        rep(i,n){
            int a;Sc(a);
            //cout<<a<<": ";
            ins(a);
            //cout<<endl;
        }
        rep(i,m){
            int a;Sc(a);
            
			//cout<<endl;
            cout<<fid(a)<<endl;
            //printf("%d\n",fid(a));
        }
    }

}