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
# define ww(a) while(a)
# define sc(x) scanf("%d",&(x))
# define sl(x) scanf("%I64d",&(x))
# define pc(x) printf("%d\n",(x));
# define pl(x) printf("%I64d\n",(x));
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 1000020

int a[maxn];
int sg[maxn];
int n;
int main()
{
	wT(){
		sc(n);
		rep(i,n){
			sc(a[i]);
			if(a[i]%4 == 1||a[i]%4 == 2)sg[i] = a[i];
			else if(a[i]%4 == 3)sg[i] = a[i]+1;
			else if(a[i]%4 == 0)sg[i] = a[i]-1;
		}
		int flag = 0;
		rep(i,n)flag ^= sg[i];
		if(flag)printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
} 