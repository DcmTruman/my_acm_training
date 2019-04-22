#include<iostream>
#include<string>
#include<set>
#include<string.h>

using namespace std;

int main()
{
	set<string>S;
	int N;
	cin>>N;
	for(int T = 1;T<=N;T++)
	{
		S.clear();
		string s1,s2,s3,s4;
		int c;
		cin>>c>>s1>>s2>>s3;
		s4 = s3;
		int cnt = 0;
		while(1)
		{
			int index = 0;
			for(int i = 0;i<c;i++)
			{
				s4[index++] = s2[i];
				s4[index++] = s1[i];
			}
			//cout<<"Debug: "<<s4<<endl;
			cnt++;
			if(s4 == s3)
			{
				cout<<T<<" "<<cnt<<endl;
				break;
			}
			if(S.count(s4))
			{
				cout<<T<<" -1"<<endl;
				break; 
			}
			else
			{
				S.insert(s4);
				s1.assign(s4,0,c);
				s2.assign(s4,c,c);	
			}
		}
	}
	
} 