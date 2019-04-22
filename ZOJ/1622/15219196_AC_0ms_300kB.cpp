#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;


bool arr[10020];

int main()
{
	int N;
	while(cin>>N)
	{
		memset(arr,0,sizeof(arr));
		for(int i = 0;i<N;i++)cin>>arr[i];
		int cnt1 = 0;
		int cnt2 = 0;
		for(int i = 0;i<N;i++)
		{
			if(i%2==0&&arr[i])cnt1++;
			if(i%2==1&&!arr[i])cnt1++;
		}
		for(int i = 0;i<N;i++)
		{
			if(i%2==0&&!arr[i])cnt2++;
			if(i%2==1&&arr[i])cnt2++;	
		}
		cout<<min(cnt1,cnt2)<<endl;
	}
	
}