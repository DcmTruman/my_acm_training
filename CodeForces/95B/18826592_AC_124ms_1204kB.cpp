#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <algorithm>

#define ll long long
using namespace std;
int main()
{
	string s;
	int ctt = 0;
	while(cin >> s)
	{
	int le = s.length();
	int t4 = 0;
	int t7 = 0;
	if(le & 1){
		for(int i = 0;i<le/2+1;i++)cout << "4";
		for(int i = 0;i<le/2+1;i++)cout << "7";
		cout << endl;
		continue;
	}
	int cnt4 = le / 2;
	int cnt7 = le / 2;
	vector<int>ans;
	for(int i = 0;i<le;i++)
	{
		if(s[i]-'0' < 4){
			for(int j = 0;j<cnt4;j++)ans.push_back(4);
			for(int j = 0;j<cnt7;j++)ans.push_back(7);
			break;
		}else if(s[i]-'0' == 4){
			if(cnt4 >= 1){
				ans.push_back(4);
				cnt4--;
			}
			else if(cnt7 >= 1){
				ans.push_back(7);
				cnt7--;
			}
		}else if(s[i]-'0' < 7){
			if(cnt7 >= 1)
			{
				ans.push_back(7);
				cnt7--;
				for(int j = 0;j<cnt4;j++)ans.push_back(4);
				for(int j = 0;j<cnt7;j++)ans.push_back(7);
				break;
			}
			else 
			{
				int pos = -1;
				int temp_cnt7 = cnt7;	
				for(int j = ans.size() -1;j>=0;j--){
					if(ans[j] == 4 && temp_cnt7>0){
						pos = j;
						break;
					}else if(ans[j] == 7){
						temp_cnt7 ++;
					}
				}
				if(pos == -1){
					ans.clear();
					for(int j = 0;j<le/2 + 1;j++)ans.push_back(4);
					for(int j = 0;j<le/2 + 1;j++)ans.push_back(7);
					break;
				}else{
					int sz = ans.size();
					for(int j = 0;j<sz - pos - 1;j++){
						if(ans.back() == 4)cnt4 ++;
						else cnt7++;
						ans.pop_back();
					}
					if(cnt7 >= 1){
						ans[ans.size() - 1] = 7;
						cnt4++;
						cnt7--;
						for(int j = 0;j<cnt4;j++)ans.push_back(4);
						for(int j = 0;j<cnt7;j++)ans.push_back(7);
						break;	
					}else{
						ans.clear();
						for(int j = 0;j<le/2 + 1;j++)ans.push_back(4);
						for(int j = 0;j<le/2 + 1;j++)ans.push_back(7);
						break;
					}
				}
			}
		}else if(s[i]-'0' == 7){
			if(cnt7 >= 1){
				ans.push_back(7);
				cnt7--;
			}else{
				int pos = -1;
				int temp_cnt7 = cnt7;
				for(int j = ans.size() -1;j>=0;j--){
					if(ans[j] == 4 && temp_cnt7>0){
						pos = j;
						break;
					}else if(ans[j] == 7){
						temp_cnt7 ++;
					}
				}
				if(pos == -1){
					ans.clear();
					for(int j = 0;j<le/2 + 1;j++)ans.push_back(4);
					for(int j = 0;j<le/2 + 1;j++)ans.push_back(7);
					break;
				}else{
					int sz = ans.size();
					for(int j = 0;j<sz - pos - 1;j++){
						if(ans.back() == 4)cnt4 ++;
						else cnt7++;
						ans.pop_back();
					}
					if(cnt7 >= 1){
						ans[ans.size() - 1] = 7;
						cnt4++;
						cnt7--;
						for(int j = 0;j<cnt4;j++)ans.push_back(4);
						for(int j = 0;j<cnt7;j++)ans.push_back(7);
						break;	
					}else{
						ans.clear();
						for(int j = 0;j<le/2 + 1;j++)ans.push_back(4);
						for(int j = 0;j<le/2 + 1;j++)ans.push_back(7);
						break;
					}
			}
				
		}}else if(s[i] > 7){
			int pos = -1;
			int temp_cnt7 = cnt7;
			for(int j = ans.size() -1;j>=0;j--){
					if(ans[j] == 4 && temp_cnt7>0){
						pos = j;
						break;
					}else if(ans[j] == 7){
						temp_cnt7 ++;
					}
			}
			if(pos == -1){
				ans.clear();
				for(int j = 0;j<le/2 + 1;j++)ans.push_back(4);
				for(int j = 0;j<le/2 + 1;j++)ans.push_back(7);
				break;
			}else{
				int sz = ans.size();
				for(int j = 0;j<sz - pos - 1;j++){
					if(ans.back() == 4)cnt4 ++;
					else cnt7++;
					ans.pop_back();
				}
				if(cnt7 >= 1){
					ans[ans.size() - 1] = 7;
					cnt4++;
					cnt7--;
					for(int j = 0;j<cnt4;j++)ans.push_back(4);
					for(int j = 0;j<cnt7;j++)ans.push_back(7);
					break;	
				}else{
					ans.clear();
					for(int j = 0;j<le/2 + 1;j++)ans.push_back(4);
					for(int j = 0;j<le/2 + 1;j++)ans.push_back(7);
					break;
				}
			}
		}
	}
	for(int i = 0;i<ans.size();i++)cout << ans[i];
	cout << endl;
	}
return 0;
}
