	#include<iostream>
	#include<set>
	#include<algorithm>
	using namespace std ;
	set<int>s;
	int main()
	{
		int n,m;
		cin>>n>>m;
		int flag = 0;
		int flag2 = 0;
		while(m--)
		{
			s.clear();
			int k;
			int flag1 = 0;
			cin>>k;
			for(int i=0;i<k;i++)
				{
					int a;
					cin>>a;
					if(s.count(-a)){flag1=1;}
					s.insert(a);
				}
			if(flag1 == 0&&!flag2){flag=0;flag2 = 1;}
			else if(flag1 == 1&&!flag2){flag = 1;}
		}
		if(flag ==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}