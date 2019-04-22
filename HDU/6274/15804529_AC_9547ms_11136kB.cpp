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
# define Inf 0x7f7f7f7f
# define clr0(x) memset(x,0,sizeof(x))
# define clr1(x) memset(x,INF,sizeof(x))
# define clrf(x) memset(x,-1,sizeof(x))
# define rep(i,a) for(int i = 0;i<(a);i++)
# define repf(i,a,b) for(int i = (a);i<=(b);i++)
# define repu(i,a,b) for(int i = (a);i<(b);i++)
# define repd(i,a,b) for(int i = (a);i>=(b);i--)
# define lowbit(x) ((x)&(-x))
# define ww(a) while(a)
# define sc(x) scanf("%d",&(x))
# define sl(x) scanf("%lld",&(x)
# define pc(x) printf("%d\n",(x));
# define pl(x) printf("%lld\n",(x));
# define scf scanf
# define prf printf
# define wT() int T;scanf("%d",&T);while(T--)
# define wt() int T;scanf("%d",&T);for(int tt = 1;tt<=T;tt++)
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 200020

using namespace std;

ll A[1020][1020];
ll num[1020];
ll aa[100020];
ll bb[100020];
ll z;
int n,m;
int add(int x,int y,ll val)
{
    while(y<=1000){
        A[x][y] += val;
        y += lowbit(y);
    }
}

ll sum(int x,int y)
{
    ll ret = 0;
    while(y){
        ret += A[x][y];
        y -= lowbit(y);
    }  
    return ret;
}

ll funcS(ll t)
{
    ll ret = 0;
    ll yu;
    repf(a,1,1000){
        //cout<<a<<endl;
        ret += num[a]*(t/a);
        yu = t%a+1;
        int nn = sum(a,1000)-sum(a,yu);//余数大的个数，要减1*nn
        ret -= nn;
    }
    return ret;
}
int tmp;
int tmpx,tmpy;
int main()
{
    fuckio
    wT(){
        clr0(A);
        clr0(num);
        ll z = 0;
        scanf("%d%d",&n,&m);
        repf(i,1,n){
            sc(aa[i]);num[aa[i]]++;    
        }
        repf(i,1,n){
            sc(bb[i]);z += bb[i]/aa[i];
            add(aa[i],(bb[i]%aa[i]+1),1);
        }
        ww(m--){
            sc(tmp);
            if(tmp == 1){
                sc(tmpx);sc(tmpy);
                num[aa[tmpx]]--;
                add(aa[tmpx],(bb[tmpx]%aa[tmpx]+1),-1);
                z -= bb[tmpx]/aa[tmpx];
                aa[tmpx] = tmpy;
                z += bb[tmpx]/aa[tmpx];
                add(aa[tmpx],(bb[tmpx]%aa[tmpx]+1),1);
                num[aa[tmpx]]++;
                
            }
            else if(tmp == 2){
                sc(tmpx);sc(tmpy);
                add(aa[tmpx],(bb[tmpx]%aa[tmpx]+1),-1);
                z -= bb[tmpx]/aa[tmpx];
                bb[tmpx] = tmpy;
                z += bb[tmpx]/aa[tmpx];
                add(aa[tmpx],(bb[tmpx]%aa[tmpx]+1),1);
            }
            else if(tmp == 3){
                ll k;
                scanf("%lld",&k);
                k += z;
                ll high = 1e11;
                ll low = 0;
                ll mid;
                // repf(i,1,3000){
                //     if(funcS(i)>=tmpx){cout<<i<<endl;break;}
                // }
                ww(low<=high){
                    mid = (low+high)/2;
                    //cout<<mid<<endl;
                    if(funcS(mid)>=k){
                        high = mid-1;
                    }
                    else{
                        low = mid+1;
                    }
                }
                prf("%lld\n",high+1);
            }
        }
        
    }
}