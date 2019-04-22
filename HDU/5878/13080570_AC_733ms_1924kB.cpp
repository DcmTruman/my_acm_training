    #include<iostream>  
    #include<cstdio>  
    #include<cstring>  
    #include<algorithm>  
    #include<string>  
    #include<vector>  
    #include <ctime>  
    #include<queue>  
    #include<set>  
    #include<map>  
    #include<list>  
    #include<stack>  
    #include<iomanip>  
    #include<cmath>  
    #include<bitset>  
    #define mst(ss,b) memset((ss),(b),sizeof(ss))  
    ///#pragma comment(linker, "/STACK:102400000,102400000")  
    typedef long long ll;  
    typedef long double ld;  
    #define INF (1ll<<60)-1  
    #define Max 1e9  
    using namespace std;  
    int T;  
    ll anw[1000100];  
    ll Pow(int x,int num){  
        ll ans=1LL;  
        for(int i=1;i<=num;i++) ans=ans*1LL*x;  
        return ans;  
    }  
    ll n;  
    int main(){  
        int cnt=0;  
        for(int i=0;i<=31;i++){  
            for(int j=0;j<=19;j++){  
                for(int k=0;k<=12;k++){  
                    for(int l=0;l<=11;l++){  
                        ll tmp=Pow(2,i)*Pow(3,j);  
                        if(tmp>1e9) break;  
                        tmp*=Pow(5,k);  
                        if(tmp>1e9) break;  
                        tmp*=Pow(7,l);  
                        if(tmp>1e9) break;  
                        anw[++cnt]=tmp;  
                    }  
                }  
            }  
        }  
        sort(anw+1,anw+cnt+1);  
        scanf("%d",&T);  
        while(T--){  
            scanf("%I64d",&n);  
            int x=lower_bound(anw+1,anw+cnt+1,n)-anw;  
            printf("%I64d\n",anw[x]);  
        }  
        return 0;  
    }  