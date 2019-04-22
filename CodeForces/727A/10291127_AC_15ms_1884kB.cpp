#include<iostream>
#include<vector>
using namespace std;
vector<int>V;
int main()
{
    int a,b;
    cin>>a>>b;
    V.push_back(b);
    while(a<b)
    {
        if(b%10 == 1){b = (b-1)/10;V.insert(V.begin(), b);}
        else if (!(b&1)) {b = b/2;V.insert(V.begin(), b);}
        else break;
    }
        if(a == b){
            cout<<"YES\n"<<V.size()<<"\n"<<a<<" ";
        
            for(int i=1;i<V.size();i++){
                cout<<V[i]<<" ";
            }
        }
    else cout<<"NO";
}