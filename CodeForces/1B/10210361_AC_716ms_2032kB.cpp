#include<iostream>
#include<string>
#include<stack>
using namespace std;
long long POW(long long a,long long b)
{
	long long c=1;
	for(long long i=0;i<b;i++)
	{
		c *= a;
	}
	return c;
}
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		string s;
		long long r=0,c=0;
		int type = 0,flag=0;
		cin>>s;
		for(int i=1;i<s.length()-1;i++)
		{
			if(s[i]=='C'&&s[i-1]<=57&&s[i+1]<=57){type = 1;flag=i+1;break;}
		}
		if(type == 0)
		{
			int count = 0;
			for(int i=0;i<s.length()-1;i++)
			{
				if(s[i]>57)count++;
				else break;
			}
			for(int i=0;i<count;i++)
			{
				c +=  (s[i]-'A'+1)*POW(26,count-1-i);
			}
			cout<<"R"<<s.substr(count,s.length()-count)<<"C"<<c<<endl;
		}
		else
		{
			for(int i=flag;i<s.length();i++)
			{
				c += (s[i]-'0')*POW(10,s.length()-i-1);
			}
			//cout<<c<<endl;
			stack<char>S;
			while(c>26)
			{
				int t = c%26;
				if(t==0)t=26;
				S.push('A'-1+t);
				c /=26;
				if(t==26)c -=1;
			}
			S.push('A'-1+c);
			while(!S.empty())
			{
			cout<<S.top();
			S.pop();
			}
			for(int i = 1;i<flag-1;i++)
			{
				cout<<s[i];
			}
			cout<<endl;
		}
	}
}