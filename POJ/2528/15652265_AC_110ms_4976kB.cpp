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
# define Sc(x) scanf("%lld",&(x))
# define Lson(x) ((x)<<1)
# define Rson(x) (((x)<<1)|1)
# define fuckio() ios::sync_with_stdio(false)
# define fuck() cout<<"fuck:"<<__LINE__<<endl

typedef long long ll;
ll ans;
const int maxn = 100200;
using namespace std;
int T,aa,bb,cc;
int n,m;
char c;
vector<int>V;
int li[maxn];
int a[maxn<<2];
int ri[maxn];
bool visit[maxn<<4];
int getid(int x){return lower_bound(V.begin(),V.end(),x)-V.begin()+1;}

struct node
{
    int l,r,num;
}tree[maxn<<4];

struct ttt{
    int l,r;
}e[maxn<<3];
void pushdown(int x)
{
    if(tree[x].num == 0)return;
    tree[Lson(x)].num = tree[Rson(x)].num = tree[x].num;
    tree[x].num = 0;
}


void build(int x,int l,int r)
{
    tree[x].l = l;tree[x].r = r;
    tree[x].num= 0;
    //tree[x].sum = 1;
    if(l == r){
        //tree[x].sum = 1;
        return;
    }
    int mid = (l+r)/2;
    build(Lson(x),l,mid);
    build(Rson(x),mid+1,r);
}

void update(int x,int l,int r,int v)
{
    int L = tree[x].l;int R = tree[x].r;
    if(l<=L&&R<=r){
        //cout<<L<<" "<<R<<endl;
        tree[x].num = v;
        return;
    }
    pushdown(x);
    int mid = (L+R)/2;
    if(mid>=l)update(Lson(x),l,r,v);
    if(r>=mid+1)update(Rson(x),l,r,v);
    //pushup(x);
}

void query(int x,int l,int r)
{
    if(tree[x].num!=0){
        if(!visit[tree[x].num]){
            visit[tree[x].num] = true;
            ans ++;
        }
        return;
    }
    
    int mid = (l+r)/2;
    //int ans = 0;
    query(Lson(x),l,mid);
    query(Rson(x),mid+1,r);
}

int main()
{
    // fuckio();
    // cin>>T;
    // W(T--){
    //     V.clear();
    //     clr0(visit);
    //     scanf("%d",&n);
    //     repf(i,1,n){
    //         scanf("%d%d",&li[i],&ri[i]);
    //         V.push_back(li[i]);
    //         V.push_back(ri[i]);
    //     }
    //     sort(V.begin(),V.end());V.erase(unique(V.begin(),V.end()));
    //     int len = V.size();
    //     for(int i = 0;i<len-2;i++){
    //         if(V[i+1]-V[i]>1)V.push_back(V[i+1]-1);
    //     }
    //     sort(V.begin(),V.end());
    //     int R = 0;
    //     repf(i,1,n){
    //         R = max(R,getid(ri[i]));
    //     }
    //     build(1,1,R);
    //     repf(i,1,n){
    //         update(1,getid(li[i]),getid(ri[i]),i);
    //     }
    //     ans = 0;
    //     query(1,1,R);
    //     cout<<ans<<endl;
    // }

    int casen;
    int n;
    cin>>casen;
    while(casen--)
    {
        clr0(visit);
        clr0(a);
        clr0(li);
        clr0(ri);
        int id=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&li[i],&ri[i]);
            a[++id]=li[i];
            a[++id]=ri[i];
        }
        int cnt=1;
        sort(a+1,a+id+1);
        for(int i=2;i<=id;i++)
        {
            if(a[i]!=a[i-1])
                a[++cnt]=a[i];
        } //去重 
        ans=0;
        int R=0;
        for(int i=1;i<=n;i++)
        {
            int ul=lower_bound(a+1,a+1+cnt,li[i])-a;
            int ur=lower_bound(a+1,a+1+cnt,ri[i])-a;
            e[i].l=ul;
            e[i].r=ur;
            //fuck();
            R=max(R,e[i].r);
        }//离散化缩短区间长度 
       // fuck();
        build(1,1,R);
       // fuck();
        for(int i=1;i<=n;i++)
        {
          //  update(tree[i].l,tree[i].r,1,i);  
          //fuck();  
            update(1,e[i].l,e[i].r,i);
        }
        query(1,1,R);
        cout<<ans<<endl;
    }
    return 0;   

}