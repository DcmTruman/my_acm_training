#include<iostream>
#include<algorithm>
using namespace std;
 int main()
 {
	long long n,k;
	cin>>n>>k;
	long long temp = n/k;
	if(temp%2)cout<<"YES";
	else cout<<"NO";
 }