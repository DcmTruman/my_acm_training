#include<iostream>
#include<map>
#include<set>
#include<string>


using namespace std;






int main()
{
	
	int m,n;
	
	while(cin>>n>>m)
	{
		//string s;
		getchar();
		int kk = 0;
		map<string,int>Ms;
		map<int,int>ans;
		int ms[10020][12];

		for(int i = 0;i<n;i++)
		{
			string s;
			getline(cin,s);
			int ps = 0;//开始位置 
			int pe = s.find(',',0);//子串结束位置 
			for(int j = 0;j<m;j++)
			{
				if(j == m-1)
				
				{
					string s1(s.begin()+ps,s.end());
					if(Ms.count(s1))
					{
						ms[i][j] = Ms[s1];
					}
					else
					{
						Ms[s1] = kk;
						ms[i][j] = kk;
						kk++;
					}	
				}
				else
				{
					string s1(s.begin()+ps,s.begin()+pe);
					ps = pe+1;
					pe = s.find(',',ps);
					if(Ms.count(s1))
					{
						ms[i][j] = Ms[s1];
					}
					else
					{
						Ms[s1] = kk;
						ms[i][j] = kk;
						kk++;
					}	
				}
				
			}
		}
		
		int ans1; 
		bool flag = false;
		int tt;
		int temp;
		for(int i = 0;i<m-1;i++)
		{
			for(int j = i+1;j<m;j++)
			{
				tt = i*100120+j;//两列的唯一映射 
				for(int k = 0;k<n;k++)
				{
					temp = ms[k][i]*100120+ms[k][j];//两个字符串的唯一映射 
					
					if(ans.count(temp))
					{
						ans1 = k;
						flag = true;
						break;
					}
					ans[temp] = k;
				}
				if(flag)
				{
					break;
				}
				ans.clear();
			}
			if(flag)
			{
				break;
			}
		}
		if(!flag)cout<<"YES"<<endl;
		else
		{
			cout<<"NO"<<endl;
			cout<<ans[temp]+1<<" "<<ans1+1<<endl;
			cout<<tt/100120+1<<" "<<tt%100120+1<<endl;
		}
		
		
	
	}
	
	return 0;
	
}


/*
3 3
How to compete in ACM ICPC,Peter,peter@neerc.ifmo.ru
How to win ACM ICPC,Michael,michael@neerc.ifmo.ru
Notes from ACM ICPC champion,Michael,michael@neerc.ifmo.ru
2 3
1,Peter,peter@neerc.ifmo.ru
2,Michael,michael@neerc.ifmo.ru
*/