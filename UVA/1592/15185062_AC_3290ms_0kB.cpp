#include<iostream>
#include<string>
#include<map>
#include<cstdio>
 
using namespace std;
int num[10010][15];
int m,n;
 
void input(){
    map<string, int> mp;
    int cnt(0);
    for(int mi=0; mi<m ; mi++){
        string s_;
        getline(cin,s_);
 
        int st(0);
        int en=s_.find(',',0);
 
        for(int i =0;i<n;i++){
            if(i==n-1){
                string s1( s_.begin()+ st , s_.end());
                if(mp.count(s1)) num[mi][i]=mp[s1];
                else num[mi][i]=(mp[s1]=cnt++);
            }
            else{
                string s1( s_.begin()+ st , s_.begin()+en);
                st=en+1;
                en=s_.find(',',st);
                if(mp.count(s1)) num[mi][i]=mp[s1];
                else num[mi][i]=(mp[s1]=cnt++);
            }
        }
    }
}
 
void solve(){
    for(int i =0;i<m-1;i++)
    for(int j=i+1;j<m;j++){
        int have=0;
        int c[2];
        for(int k=0;k<n;k++){
            if(num[i][k]==num[j][k]){
                c[have++]=k;
                if(have==2){
                    cout<<"NO"<<endl;
                    cout<<i+1<<" "<<j+1<<endl;
                    cout<<c[0]+1<<" "<<c[1]+1<<endl;
                    return;
                }
            }
        }
 
    }
    cout<<"YES"<<endl;
}
 
int main(){
    while(cin>>m>>n){cin.get();
        input();
        solve();
    }
    return 0;
}