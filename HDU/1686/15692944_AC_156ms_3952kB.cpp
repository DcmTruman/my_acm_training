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
# define W(a) while(a)
# define Sc(x) scanf("%d",&(x))
# define Sd(x) scanf("%I64d",&(x))
# define Lson(x) (x)<<1
# define Rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fucl:"<<__LINE__<<endl;
# define gcd(a,b) __gcd((a),(b))
# define maxn 10020
using namespace std;

int nexta[maxn];
void getnxt(string s)
{
    clr0(nexta);
    int m = s.length();
    nexta[0] = -1;
    int i = -1,j = 0;
    W(j<m){
        if(i==-1||s[i]==s[j]){
            nexta[j+1] = i+1;
            i++;j++;
        }else {
            i = nexta[i];
        }
    }
}

int kmp(string s,string t)//t为模式串，s为原串
{
    getnxt(t);
    int res = 0;
    int i = 0,j =0 ;
    int n = s.length();
    int m = t.length();
    W(i<n){
        if(j==-1||s[i] == t[j]){
            i++;j++;
        }else{
            j = nexta[j];
        }
        if(j == m){
            res ++;
            j = nexta[j];
        }
    }
    return res;
}
int main()
{
    fuckio
    string s;
    string t;
    int T;
    cin>>T;
    W(T--){
       cin>>t>>s;
       cout<<kmp(s,t)<<endl;
    }
}
