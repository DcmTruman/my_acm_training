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

int getmin(char *str){
    int i = 0, j = 1;
    int l;
    int len = strlen(str);
    while (i < len && j < len) {
        for (l = 0; l < len; l++)
            if (str[(i + l) % len] != str[(j + l) % len]) break;
        if (l >= len) break;
        if (str[(i + l) % len] > str[(j + l) % len]) i = i + l + 1;
        else j = j + l + 1;
        if (i == j) j++;
    }
    return i < j ? i : j;
}

int getmax(char *str){
    int i = 0, j = 1, k = 0;
    int len = strlen(str);
    while (i < len && j < len && k < len) {
        int t = str[(i + k) % len] - str[(j + k) % len];
        if (!t) k++;
        else {
            if (t > 0) j = j + k + 1;
            else i = i + k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    return i < j ? i : j;
}


int n;
char s[maxn];
int main()
{
    fuckio
    ww(scanf("%s",s)!=EOF){
        int len = strlen(s);
        kmp.init();
        kmp.getnext(s);
        int Min = getmin(s);
        int Max = getmax(s);
        int tmp = 0;
        if(len%(len-kmp.nexta[len]) == 0)tmp = len/(len-kmp.nexta[len]);
        else tmp =  1;
        printf("%d %d %d %d\n", Min + 1, tmp, Max + 1, tmp);
    }
}
