#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
 int te[25]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
 int ty[15] = {0,0,6,6,5,5,5,7,6,6};
int main()
{
	int N,ans = 0;
	cin>>N;
	while(N--)
	{
		int sum = 0;
		int num;
		cin>>num;
		if(num>=100&&num<=999)
		{
			int a = num/100;
			int b = num - 100*a;
			if(b==0)sum += te[a]+7;
			else if(b>=20)
			{
				int c = b/10;
				int d = b-c*10;
				sum += te[a]+10+ty[c]+te[d];
			}
			else if(b<20)
			{
				sum +=  te[a]+10+te[b];
			}
		}
		else if(num == 1000)sum+=11;
		else if(num<100&&num>=20)
		{
			int c = num/10;
			int d = num-c*10;
			sum += ty[c]+te[d];
		}
		else if(num<20)
		{
			sum += te[num];
		}
		ans +=sum;
		cout<<ans<<endl;
	}
	//cout<<ans<<endl;
}