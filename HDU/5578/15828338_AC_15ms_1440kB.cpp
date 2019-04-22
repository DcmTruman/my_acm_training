#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;
const int INF=10000000;
vector<int> v[26];
string s;
int main()
{
    int T,i,len,j,ans,kase=1;
    cin>>T;
    while (T--) {
        for (i=0;i<26;i++) v[i].clear();
        cin>>s; len=s.length();
        for (i=0;i<len;i++) v[s[i]-'a'].push_back(i);
        ans=INF;
        for (i=0;i<26;i++) {
            if (v[i].size()<=1) continue;
            for (j=0;j<v[i].size()-1;j++)
                ans=min(ans,v[i][j+1]-v[i][j]);
        }
        cout<<"Case #"<<kase++<<": ";
        if (ans==INF) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}