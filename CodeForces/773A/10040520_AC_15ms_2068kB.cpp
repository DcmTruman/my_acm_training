#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//long long gcd(long a,long b)
//{
//    while( a!=b )
//    {
//        if ( a>b )
//            a-=b;
//        else
//            b-=a;
//    }
//    return b;
//}
long long getOutput(long long x,long long y,long long p,long long q)
{
	long long N ;
	long long count;
	if(p==q){
		return(x==y?0:-1);
	}
	if(p==0){
		return (x==0?0:-1);
	}
	//long long GCD=gcd(p,q);
 //   p/=GCD;q/=GCD;
	N = max(ceil(x*1.0/p),ceil((x-y)*1.0/(p-q)));
	count = N*q-y;
	return count;
}
int main()
{
	int N;
	cin>>N;
	vector<long long>V;
	for(int i = 0;i<N;i++)
	{
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		V.push_back(getOutput(a,b,c,d));
	}
	for(int i = 0;i<N;i++)
	{
		cout<<V[i]<<endl;
	}
}