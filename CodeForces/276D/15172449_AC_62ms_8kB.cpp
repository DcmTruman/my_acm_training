#include<iostream>
#include<math.h>
#include<string>


using namespace std;

typedef long long ll;
int main()
{
	ll l,r,pos = 0;
	cin>>l>>r;
	string s1 = "",s2 = "";
	
	if(l == r)cout<<"0\n";
	else{
	
	
	while(l)
	{
		int t = l%2;
		if(t)s1.insert(0,"1");
		else s1.insert(0,"0");
		l /= 2;
	}
	
	while(r)
	{
		int t = r%2;
		if(t)s2.insert(0,"1");
		else s2.insert(0,"0");
		r /= 2;
	}
	
	
	int len = s2.length();
	
	if(s1.length()<len)
	{
		for(int i = 0;i<len-s1.length();i++)
		{
			s1.insert(0,"0");
		}
	}
	
	//cout<<s1<<"\n"<<s2<<endl;
	for(int i = 0;i<len;i++)
	{
		if(s1[i] == '0'&&s2[i] == '1')
		{
			pos = len-i;
			break;
		}
	}
	printf("%I64d",(ll)pow(2,pos)-1);
}
	return 0;
	
	
}