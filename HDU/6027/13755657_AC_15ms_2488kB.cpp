#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<cmath>  
using namespace std;  
#define ll long long   
ll mod = 1e9+7;  
ll a[10005][10];  
ll mul(ll a,ll b){  
    ll res=1;  
    while(b){  
        if(b%2){  
            res=(res*a)%mod;  
        }  
        a=(a*a)%mod;  
        b/=2;  
    }  
    return res;  
}  
int main(){   
    int t;  
    cin>>t;  
    for(int i=0;i<=5;i++){  
        for(int j=1;j<=10001;j++){  
            a[j][i]=(a[j-1][i]+mul((ll)j,(ll)i))%mod;  
        }  
    }  
    while(t--){  
        int n,m;  
        cin>>n>>m;  
        cout<<a[n][m]<<endl;  
    }  
    return 0;  
}