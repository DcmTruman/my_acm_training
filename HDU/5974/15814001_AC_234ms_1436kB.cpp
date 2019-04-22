#include<iostream>
#include<cmath>
using namespace std;
int gcd(int n,int m)
{
    if (m==0) return n;
    return gcd(m,n%m);
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m,i,i0,x1,x2,ansx,ansy;
    while (cin>>n>>m) {
        bool bo=false;
        for (i=1;i*i<=n;i++) {
            if (n%i==0) {
                if (m%i==0&&n*n>=4.0*m*i) {
                    int x1=ceil((n-sqrt(n*n-4.0*m*i))/2);
                    int x2=floor((n-sqrt(n*n-4.0*m*i))/2);
                    //cout<<i<<" "<<x1<<" "<<x2<<endl;
                    if ((x1*(n-x1)==m*i&&gcd(x1,n-x1)==i)) {
                        bo=true; ansx=x1;ansy=n-x1;break;
                    }
                    if ((x2*(n-x2)==m*i&&gcd(x2,n-x2)==i)) {
                        bo=true; ansx=x2;ansy=n-x2;break;
                    }
                }
                i0=n/i;
                if (m%i0==0&&n*n>=4.0*m*i0) {
                    x1=ceil((n-sqrt(n*n-4.0*m*i0))/2);
                    x2=floor((n-sqrt(n*n-4.0*m*i0))/2);
                    //cout<<i0<<" "<<x1<<" "<<x2<<endl;
                    if (x1*(n-x1)==m*i0&&gcd(x1,n-x1)==i0) {
                        bo=true; ansx=x1;ansy=n-x1;break;
                    }
                    if (x2*(n-x2)==m*i0&&gcd(x2,n-x2)==i0) {
                        bo=true; ansx=x2;ansy=n-x2;break;
                    }
                }
            }
        }
        if (bo) cout<<ansx<<" "<<ansy<<endl;
        else cout<<"No Solution"<<endl;
    }
    return 0;
}