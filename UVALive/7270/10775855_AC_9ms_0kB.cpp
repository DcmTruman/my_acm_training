#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int ans=0;
		for(int i=0;i<n;i++){
			char c;
			cin>>c;
			if(c=='C'||c=='B'){
				int te;cin>>te;
				if(te==1){
					ans++;
				}
			}else if(c=='S'){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}