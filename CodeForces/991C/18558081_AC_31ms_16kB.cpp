#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

bool isok(ll now , ll n)
{
	ll sum = 0;
	ll fi = n;
	//if(now == 0)return false;
	while(n)
	{
		if(n <= now){
			sum += n;
			break;
		}	
		n -= now;
		sum += now;
		n -= n/10;
	}
	if(sum >= (fi+1)/2)return true;
	else return false;
}
int main()
{
	ll k , n;
cin >> n;
	//while(cin >> n)
	//{
		ll low = 1ll;
		ll high = n;
		while(low < high)
		{
			ll mid = (low + high) / 2;
//			if(1)cout << low << " " << mid << " " << high << endl;
			if(isok(mid , n)){
				high = mid  ;
			}else{
				low = mid + 1;
			}
		}
		cout << low  << endl;
	//}

return 0;
}
