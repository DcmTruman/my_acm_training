#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<stdio.h>
#define clr(x,b) memset(x,(b),sizeof(x));
using namespace std;

typedef long long ll;

const int maxn = 1e5+7;

double dp[maxn];

void init(){
    for(int i = 2;i<maxn;i++){
        //cout<<"fuck"<<endl;
        double s = 0;
        int cnt = 0;
        for(int j = 1;j*j<=i;j++){
            if(i%j==0){
                s += dp[j];
                cnt++; 
                if(j!=i/j){
                    s += dp[i/j];
                    cnt++;
                }
            }
        }
        dp[i] = (s+cnt)/(cnt-1);
    }
}
int main()
{
    clr(dp,0);
    init();
    int T;cin>>T;
    for(int i = 1;i<=T;i++){
        int n;cin>>n;
        printf("Case %d: %.10lf\n",i,dp[n]);
    }
}