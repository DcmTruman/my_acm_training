#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pi acos(-1)
#define ll long long
#define mod 1000000007
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1

using namespace std;

const double g=10.0,eps=1e-9;
const int N=10+5,maxn=60+5,inf=0x3f3f3f3f;

string s[N];
int Next[maxn];

void getnext(string str,int slen)
{
    int k=-1;
    Next[0]=-1;
    for(int i=1;i<slen;i++)
    {
        while(k>-1&&str[k+1]!=str[i])k=Next[k];
        if(str[k+1]==str[i])k++;
        Next[i]=k;
    }
}
bool kmp(string ptr,int plen,string str,int slen)
{
    int k=-1;
    for(int i=0;i<plen;i++)
    {
        while(k>-1&&str[k+1]!=ptr[i])k=Next[k];
        if(str[k+1]==ptr[i])k++;
        if(k==slen-1)return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 //   cout<<setiosflags(ios::fixed)<<setprecision(2);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)cin>>s[i];
        string ans="";
        for(int i=1;i<=s[0].size();i++)//长度
        {
            for(int j=0;j<=s[0].size()-i;j++)//起点
            {
                string op=s[0].substr(j,i);
                getnext(op,op.size());
                bool flag=0;
                for(int k=1;k<n;k++)
                    if(!kmp(s[k],s[k].size(),op,op.size()))
                        flag=1;
                if(!flag)
                {
                    if(ans.size()<op.size())ans=op;
                    else if(ans.size()==op.size())ans=min(ans,op);
                }
            }
        }
        if(ans.size()<3)cout<<"no significant commonalities"<<endl;
        else cout<<ans<<endl;
    }
}