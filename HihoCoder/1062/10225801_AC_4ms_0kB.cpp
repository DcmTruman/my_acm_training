#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;

int main()
{
	int N,Q;
	cin>>N;
	map<string,string>Father;
	set<string>Name;
	for(int i=0;i<N;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		Father[s2]=s1;
	}
	cin>>Q;
	while(Q--)
	{
		Name.clear();
		string n1,n2;
		
		cin>>n1>>n2;
		string temp = n1;
		Name.insert(temp);
		while(Father.count(temp))
		{
			Name.insert(Father[temp]);
			temp = Father[temp];
		}
		temp = n2;
		int flag = 1;
		if(Name.count(temp))
		{
			cout<<temp<<endl;
		}
		else{
		while(Father.count(temp))
		{
			if(Name.count(Father[temp]))
			{
				cout<<Father[temp]<<endl;
				flag=0;
				break;
			}
			temp = Father[temp];
		}
		
		if(flag)cout<<"-1"<<endl;
		}
	}
}