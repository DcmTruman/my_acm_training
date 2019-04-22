#include<stdio.h>
using namespace std;
typedef long long ll;
typedef __int128 Int128;

int scan(Int128 &x){
	x=0;
	int sgn=1;
	char ch;
	while(ch=getchar()){
		if(ch==EOF) return EOF;
		else if(ch=='-') sgn=-sgn;
		else if(ch>='0' && ch<='9'){
			x=x*10+(ch-'0'); break;
		}
	}
	while((ch=getchar())>='0' && ch<='9'){
		x=x*10+(ch-'0');
	}
	x*=sgn;
	return 1;
}

void _print(Int128 x){
	if(x>9) _print(x/10);
	putchar(x%10+'0');
}

void print(Int128 x){
	if(x<0){
		x=-x; putchar('-');
	}
	_print(x);
}


ll n,m;
ll lowbit(ll x)
{
    return x&(-x);
}

Int128 _count(Int128 x)
{
    Int128 ans=x,t=0;
    while (x) {
        x>>=1;
        ans=ans+(x<<t);
        t++;
    }
    return ans;
}

int query(ll x)
{
    int ans=0;
    while (x<=n) {
        x+=lowbit(x);
        ans++;
    }
    return ans;
}

int main()
{
    ll i,x,y;
    Int128 a,b,l,r;
    while (scanf("%lld %lld",&n,&m)!=EOF){
        for (i=0;i<m;i++) {
            scanf("%lld",&x);
            if (x==1) {
                scan(l); scan(r);
                b=_count(r);
                a=_count(l-1);
                print(b-a);
                printf("\n");
            }
            else if (x==2) {
                scanf("%lld",&y);
                printf("%lld\n",query(y));
            }
        }
    }
    return 0;
}