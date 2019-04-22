#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=10000+10;
int flag;
struct node{
    int left;
    int right;
    int num;
    int vis;
}e[maxn<<3];
int vis[maxn<<2];
struct Tree{
    int left;
    int right;
}tree[maxn<<3]; 
long long ans;
int a[maxn<<2];
int pos[maxn][2];
void pushdown(int cur)
{
    if(e[cur].num==0)    return;
    e[cur*2].num=e[cur*2+1].num=e[cur].num;//将标记传递给e[cur]的左右子树。 
    e[cur].num=0;
}
void build(int l,int r,int cur)
{
    e[cur].left=l;
    e[cur].right=r;
    e[cur].vis=0;
    e[cur].num=0;
    if(l==r)
    {
        return;
    } 
    int mid=(l+r)/2;
    build(l,mid,cur*2);
    build(mid+1,r,cur*2+1);
}
void update(int pl,int pr,int cur,int i)
{ 
    if(e[cur].left>=pl&&e[cur].right<=pr)
    {
        e[cur].num=i;    
        return;
    }
    pushdown(cur);
    int mid=(e[cur].left+e[cur].right)/2;
    if(pl<=mid)
        update(pl,pr,cur*2,i);
    if(pr>=mid+1)
        update(pl,pr,cur*2+1,i);
}
void query(int pl,int pr,int cur)
{
    if(e[cur].num!=0)
    {
        if(vis[e[cur].num]==0)//vis数组表示将已经出现的海报标记。 
        {
            ans++;
            vis[e[cur].num]=1;
        }
     
     return ;
    }
    
    int mid=(pl+pr)/2;//此处注意理解 不能写成mid=(e[cur].left+e[cur].right)/2; 
    query(pl,mid,cur*2);
    query(mid+1,pr,cur*2+1);
}
int main()
{
    int casen;
    int n;
    cin>>casen;
    while(casen--)
    {
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        memset(pos,0,sizeof(pos));
        int id=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&pos[i][0],&pos[i][1]);
            a[++id]=pos[i][0];
            a[++id]=pos[i][1];
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
            int ul=lower_bound(a+1,a+1+cnt,pos[i][0])-a;
            int ur=lower_bound(a+1,a+1+cnt,pos[i][1])-a;
            tree[i].left=ul;
            tree[i].right=ur;
            R=max(R,tree[i].right);
        }//离散化缩短区间长度 
        build(1,R,1);
        for(int i=1;i<=n;i++)
        {
            update(tree[i].left,tree[i].right,1,i);    
        }
        query(1,R,1);
        cout<<ans<<endl;
    }
return 0;
}