#include<iostream>
#include<string.h>
#include<string>
using namespace std;


int main()
{
	string a,b;
	cin>>a;
	cin>>b;
	int len1 = a.length();
	int len2 = b.length();
	int len = max(len1,len2);
	int cnt1 = a.length()-1;
	int cnt2 = b.length()-1;
	int tp = 0;
	for(int i = 0;i<len;i++)
	{
		if(a[cnt1--] == b[cnt2--])tp++;
		else break;
	}
	int ans = len1+len2-2*tp;
	cout<<ans<<endl;
}


