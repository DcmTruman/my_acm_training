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
# define maxn 100020


using namespace std;



typedef unsigned long long ull;
const ull base = 233;

ull hash1[maxn],hash2[maxn],p[maxn];
char s[maxn],t[30];
int cov[30];
void init(){
	p[0] = 1;
	for(int i = 1;i<maxn;i++)p[i] = p[i-1]*base;
}

ull gethash(int l,int r,ull h[])
{
	return h[r]-h[l-1]*p[r-l+1];
}




int main()
{
	fuckio
	init();
	int T;Sc(T);
	W(T--){
		clr0(cov);
		clr0(t);
		clr0(s);
		scanf("%s%s",t,s+1);
		rep(i,26){
			cov[t[i]-'a'] = i;
		}
		int len = strlen(s+1);
		hash1[0] = 0;
		hash2[0] = 0;
		repf(i,1,len){
			hash1[i] = hash1[i-1]*base+(cov[s[i]-'a']);
			hash2[i] = hash2[i-1]*base+(s[i]-'a');
		}
		int ans = len;
		repf(i,len,len*2){
			if(i&1)continue;
			int tmp = i/2;
			int cc = len-tmp;
			ull s1 = gethash(1,cc,hash1);
			ull s2 = gethash(tmp+1,len,hash2);
			//cout<<s1<<s2<<endl;
			if(s1 == s2){
				ans = tmp;
				//fuck
				break;
			}
		}
		repf(i,1,ans)printf("%c",s[i]);
		repf(i,1,ans)printf("%c",cov[s[i]-'a']+'a');
		printf("\n");
	}
return 0;
}