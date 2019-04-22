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
# define maxn 100020


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

struct EXKMP{
	int nexta[maxn];
	int extnd[maxn];
	void init(){
		clr0(nexta);
		clr0(extnd);
	}
	
	void getnxt(char *T)
	{
		init();
	    int len=strlen(T),a=0;
	    nexta[0]=len;
	    while(a<len-1 && T[a]==T[a+1]) a++;
	    nexta[1]=a;
	    a=1;
	    repf(k,2,len-1)
	    {
	        int p=a+nexta[a]-1,L=nexta[k-a];
	        if( (k-1)+L >= p)
	        {
	            int j = (p-k+1)>0 ? (p-k+1) : 0;
	            ww(k+j<len && T[k+j]==T[j]) j++;
	            nexta[k]=j;
	            a=k;
	        }
	        else
	            nexta[k]=L;
	    }
	}
	void getexnd(char *S,char *T)
	{
	    getnxt(T);
	    int slen=strlen(S),tlen=strlen(T),a=0;
	    int MinLen = slen < tlen ? slen : tlen;
	    while(a<MinLen && S[a]==T[a]) a++;
	    extnd[0]=a;
	    a=0;
	    for(int k=1; k<slen; k++)
	    {
	        int p=a+extnd[a]-1, L=nexta[k-a];
	        if( (k-1)+L >= p)
	        {
	            int j= (p-k+1) > 0 ? (p-k+1) : 0;
	            while(k+j<slen && j<tlen && S[k+j]==T[j]) j++;
	            extnd[k]=j;
	            a=k;
	        }
	        else
	            extnd[k]=L;
	    }
	}
}ekmp;

char t[maxn];
char s[maxn*2];
int main()
{
	int T;sc(T);
	repf(tt,1,T){
		kmp.init();
		ekmp.init();
		scanf("%s",t);
		strcpy(s,t);
		strcat(s,t);
		ekmp.getexnd(s,t);
		kmp.getnext(t);
		int lens = strlen(s);
		int lent = strlen(t);
		int ans1 = 0,ans2 = 0,ans3 = 0;
		rep(i,lent){
			if(ekmp.extnd[i]>=lent)ans2++;
			else{
				if(s[i+ekmp.extnd[i]]<t[ekmp.extnd[i]]){
					ans1++;
				}else{
					ans3++;
				}
			}
		}
		int pr = 1;//循环节大小 
		if(lent%(lent-kmp.nexta[lent]) == 0){
			pr = lent/(lent-kmp.nexta[lent]);
		}
		printf ("Case %d: %d %d %d\n", tt, ans1 / pr, ans2 / pr, ans3 / pr);
	}
}

