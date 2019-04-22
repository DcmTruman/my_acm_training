#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;

int aa[12];

int main()
{
	int T;
	string s;
	cin>>T;
	getchar();
	while(T--)
	{
		int n = 0;
		getline(cin,s);
		for(int i = 0;i<s.length();i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				aa[n++] = s[i] - '0';
			}
		}
		
		if(n == 2)
		{
			cout<<aa[1]-aa[0]<<endl;
			continue;
		}
		while(aa[0] == 0)next_permutation(aa,aa+n);
		
		int ans = 0x3f3f3f3f;
		
		do
		{
			int mid = (n+1)/2;
			if(aa[mid])
			{
				int a1 = 0;
				int b1 = 0;
				for(int i = 0;i<mid;i++)a1 = 10*a1+aa[i];
				for(int i = mid;i<n;i++)b1 = 10*b1+aa[i];
				ans = min(ans,abs(a1-b1));
			}
			
		}while(next_permutation(aa,aa+n));
		
		cout<<ans<<endl;
	}
}