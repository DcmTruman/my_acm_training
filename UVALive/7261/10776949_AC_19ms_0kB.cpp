#include<iostream>
#include<string.h>
using namespace std;
typedef long long LL;
LL ADD[1000020];

int main()
{
	ios::sync_with_stdio(false);
	LL T,R,N;
	cin >> T;
	while(T--)
	{
		cin >> R >> N;
		memset(ADD,0,sizeof(ADD));
		LL x,y,w,l,sum = 0;
		for(LL i =0;i<N;i++){
			cin>>x>>y>>w>>l;
			ADD[x] += l;
			ADD[x+w] -= l;
			sum += (LL)w*l;
		}

		LL temp1 = 0,temp2 = 0;
		for(int i =1;i<=R;i++)
		{
			temp1 += ADD[i];
			temp2 += temp1;
			if(temp2 >= (sum+1)/2)
			{
				while(i<R)
				{
					i++;
					temp1 +=ADD[i];
					if(temp1 != 0)break;
				}
				cout<<i<<endl;
				break;
			}

		}
	}
}