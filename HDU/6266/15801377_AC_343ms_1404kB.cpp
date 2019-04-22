#include<iostream>
using namespace std;
int main()
{
    int T,i,x,n,d,num;
    bool bo;
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--) {
        cin>>n>>d;bo=false;num=0;
        for (i=0;i<n;i++) {
            cin>>x;
            if (x==1) num++;
            else bo=true;
        }
        if (d==1) {
            if (bo) cout<<"Yes"<<endl;
            else if (num%3) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else if (d==2) {
            if ((num == n&&n%3 == 1)||(num==n-1&&(n%3==0||n%3==1))) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
    return 0;
}
