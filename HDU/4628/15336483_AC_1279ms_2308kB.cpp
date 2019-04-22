#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
char s[25];
int dp[1<<17];
int len;
int sta;
int init(int x){            //判断某个状态对应的字符串的回文串的大小,如果字符串全部回文,返回1,否则返回字符串的长度
    int ss[17]={0};
    int ans=0;
    for(int i=0;i<len;i++)
        if(x&(1<<i))
            ss[ans++]=i;
            ans--;
    for(int j=0;j<ans/2;j++) //从中点向两边看,是否回文,如果发现不回文的任意两个个字母,就返回状态x的字符串长度
        if(s[ss[j]]!=s[ss[ans-j]])
            return ans;
            return 1;
}
void solve(){
    len=strlen(s);
    sta=1<<len;//初始的状态是11111……111,就是全部都存在
    sta--;
    for(int i=1;i<=sta;i++){ //枚举各种状态,对其进行初始化
        dp[i]=init(i);//对每一个dp初始化
        for(int k=i;k>0;k=(k-1)&i) //枚举每一个状态的子状态
            dp[i]=min(dp[i],dp[k]+dp[k^i]);//子状态及其补集
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
    memset(dp,0,sizeof(dp));
    cin>>s;
    solve();
    cout<<dp[sta]<<endl;
    }
    return 0;
}