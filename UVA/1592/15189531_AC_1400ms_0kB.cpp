#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#define BIG 100100
using namespace std;

map<string,int> IDcache;
vector<string> setcache;

map<int,int> ans;
vector<vector<int> >  tab;

int ID(string x){
    if(IDcache.count(x)) return IDcache[x];
    setcache.push_back(x);
    return IDcache[x] = setcache.size() - 1;
} 

int main(){
    int n,m,c1,c2,r,val,tmp,f=0,q;
    string cmd;
    while(cin>>n>>m){
        tab.clear();
        IDcache.clear();
        setcache.clear();
        ans.clear();
        f=0;
        int row = n,col = m;
        getchar();
        while(n--){
            getline(cin,cmd);
            int cnt = 0;
            vector<int> line;
            //cout<<cmd<<endl;
            for(int i=0;i<cmd.size();i++){
                if(cmd[i] == ','){
                    string s = cmd.substr(cnt,i-cnt);
                    cnt = i+1;
                    line.push_back(ID(s));
                    //cout<<s<<":"<<ID(s)<<endl; 
                }
            }
            if(cnt<=cmd.size() ) {string s = cmd.substr(cnt,cmd.size()-cnt+1);line.push_back(ID(s));}
            tab.push_back(line);
        }

        for(c1 = 0;c1< col-1 ;c1++){
            for(c2 = c1+1;c2 < col;c2++){
                val = c1*BIG+c2;
                for(r  = 0;r < row;r++){
                    q = tab[r][c1]*BIG+tab[r][c2];
                    if(ans.count(q)) {tmp = r;f=1;break;}
                    ans[q] = r;
            }
            if(f==1) break;
            ans.clear();
        }
        if(f==1) break;
        }

        if(f==0) cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
            cout<<ans[q]+1<<" "<<tmp+1<<endl;
            cout<<val/BIG+1<<" "<<val%BIG+1<<endl;
        }
    }
    return 0;
}