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
# define ww(a) while(a)
# define sc(x) scanf("%d",&(x))
# define pc(x) printf("%d\n",(x));
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 1000020


using namespace std;

const int mod = 1e4+7;

struct KMP{
	int nexta[maxn];
	void init(){
		clr0(nexta);
	}
	void getnext(char *s){
		clr0(nexta);
		nexta[0] = -1;
		int i = -1;int j = 0;
		int n = strlen(s);
		ww(j<n){
			if(i == -1||s[i] == s[j]){
				nexta[j+1] = i+1;
				i++;j++;
			}else {
				i = nexta[i];
			}
		}
	}
	int kmp(char *s,char *t){
		int n = strlen(s);
		int m = strlen(t);
		int res = -1;
		int i = 0,j = 0;
		ww(i<n&&j<m){
			if(j == -1||s[i] == t[j]){
				i++;j++;
			}else{
				j = nexta[j];
			}
		}
		if(j == m)res = i-m;
		return res;
	}
}kmp;

char a[maxn];
int dp[maxn];
int n;

int main()
{
	int T;sc(T);
	ww(T--){
		kmp.init();
		scanf("%d%s",&n,a);
		clr0(dp);
		kmp.getnext(a);
		int ans = 0;
		repf(i,1,n){
			dp[i] = (dp[kmp.nexta[i]]+1)%mod;
			ans = (ans+dp[i])%mod;
		}
		pc(ans);
	}
}

