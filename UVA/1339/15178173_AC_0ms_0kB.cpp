#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int aa[300],bb[300];

int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		memset(aa,0,sizeof(aa));
		memset(bb,0,sizeof(bb));
		
		for(int i = 0;i<a.length();i++)
		{
			aa[a[i]]++;
			bb[b[i]]++;
		}
		sort(aa,aa+300);
		sort(bb,bb+300);
		bool ans = true;
		for(int i = 0;i<300;i++)
		{
			if(aa[i]!=bb[i])
			{
				ans = false;
				break;
			}
		}
		if(ans)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

/*
JWPUDJSTVP
VICTORIOUS
MAMA
ROME
HAHA
HEHE
AAA
AAA
NEERCISTHEBEST
SECRETMESSAGES
*/ 