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
# define Lson(x) (x)<<1
# define Rson(x) (x)<<1|1
# define ll int
# define fuckio() ios::sync_with_stdio(false)
# define fuck() cout<<"fuck:"<<__LINE__<<endl
# define maxn 100020

using namespace std;

//dp[i]
int n;
vector<int>V;

int getid(int x){return lower_bound(V.begin(),V.end(),x)-V.begin()+1;}

int xx[maxn];
int yy[maxn];
int cc[maxn];


struct point{
	int x;
	int y;
	int cost;
};

vector<point>P;

struct node
{
    int l,r,num;
    void update(ll x){
        num = x;
    }
}tree[maxn<<2];

void pushup(int x)
{
    tree[x].num= max(tree[Lson(x)].num,tree[Rson(x)].num);
}

void build(int x,int l,int r)
{
    //fuck();
    //cout<<l<<" "<<r<<endl;
    tree[x].l = l;tree[x].r = r;
    tree[x].num = 0;
    if(l == r){
        //cout<<l<<" "<<a[l]<<endl;
        tree[x].num = 0;
        return ;
    }
    int mid = (l+r)/2;
    build(Lson(x),l,mid);
    build(Rson(x),mid+1,r);
    pushup(x);
}

void update(int x,int pos,ll val)
{
    int L = tree[x].l;int R = tree[x].r;
    if(L == R){
        tree[x].update(val);
        return;
    }
    int mid = (L+R)/2;
    if(mid>=pos)update(Lson(x),pos,val);
    else update(Rson(x),pos,val);
    pushup(x);
}

ll query(int x,int l,int r)
{
    int L = tree[x].l;int R = tree[x].r;
    if(l<=L&&R<=r){
        return tree[x].num;
    }
    int mid = (L+R)/2;
    ll ans = 0;
    if(mid>=l)ans=max(ans,query(Lson(x),l,r));
    if(r>mid)ans=max(ans,query(Rson(x),l,r));
    return ans;
}

bool cmp1(point a,point b){
	if(a.y == b.y)return a.x<b.x;
	return a.y>b.y;
}
int main()

{
	int T;scanf("%d",&T);
	W(T--){
		cin>>n;
		P.clear();
		//clr0(xx);clr0(yy);clr0(cc);
		V.clear();
		repf(i,1,n){
		//	cin>>yy[i]>>xx[i]>>cc[i];
			scanf("%d%d%d",&yy[i],&xx[i],&cc[i]);
			V.push_back(xx[i]);
			//V.push_back(yy[i]);
		} 
		sort(V.begin(),V.end());
		V.erase(unique(V.begin(),V.end()),V.end());

		int mx = -1;
		int mxr = -1;
		repf(i,1,n){
			P.push_back((point){getid(xx[i]),yy[i],cc[i]});
			mxr = max(mxr,getid(xx[i]));
			//G[getid(yy[i])].push_back(i);
		}
		
		build(1,0,mxr);
		sort(P.begin(),P.end(),cmp1);
		//repf(k,1,n)cout<<xx[k]<<" ";
		rep(i,P.size()){
			int d = query(1,P[i].x+1,mxr);
			update(1,P[i].x,P[i].cost+d);
		}

		//cout<<query(1,0,mxr)<<endl;	
		printf("%d\n",query(1,0,mxr));
	}
}


/*
3
1 1 1
1 2 2
3 3 1
6
1 1 1
1 2 2
2 2 3
2 5 10
3 3 3
3 6 5

6
1 1 1
1 2 2
2 2 11
2 5 10
3 4 4
3 6 5
6
1 1 1
1 2 2
2 2 23
2 5 10
3 4 4
3 6 5
6
1 1 1
1 2 2
2 2 12
2 5 10
3 4 4
3 6 5
6
1 1 1
1 2 2
2 2 3
2 5 10
3 4 24
3 6 5
*/

 


 


