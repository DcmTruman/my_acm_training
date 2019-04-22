# include <iostream>
# include <string.h>
# include <algorithm>
# include <math.h>
# include <string>
# include <stack>
# include <map>
# include <queue>
# include <functional>
# include <vector>
# define lson(x) (x<<1)
# define rson(x) (x<<1|1)
# define debug(x) cout<<"[ Debug : "<<#x<<" , "<<x<<" ]\n"
# define fuck cout<<"LINE : "<<__LINE__<<endl;
# define fuckio ios::sync_with_stdio(false);
# define Sz(x) (int)(x).size()
# define ep empty
# define pb push_back
# define sc(x) scanf("%d",&(x));
# define pc(x) printf("%d\n",x);
# define sl(x) scanf("%lld",&(x));
# define pl(x) printf("%lld\n",x);
# define ww while
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scnaf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define rep(a,b) for(int (a) = 0;(a)<(b);(a)++)
# define repf(a,b,c) for(int (a) = b;(a)<=(c);(a)++)
# define repd(a,b,c) for(int (a) = b;(a)>=c;a--)
# define scf scanf
# define prf printf

using namespace std;


int main()
{
	fuckio
	int a,b;
	ww(~scf("%d%d",&a,&b)){
		pc(a+b);
	}
	return 0;
}