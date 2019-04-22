//by小灯
//2018年8月11日 
//先看最慢的马，如果t的最慢的马比k的快，跟它比，如果慢，跟k最快的比，如果相等，看最快的马
//如果t的最快的马比k的快，跟它比，如果慢，用最慢的马跟k最快的比，如果相等，考虑t最慢的马跟k最快的马
//如果小于，比较，如果大于等于，意味着剩下的马均相等，收缩区间，不对ans进行操作即可 
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	int a[1020];
	int b[1020];
	while(cin>>n&&n)
	{
		int ans = 0;
		for(int i = 0;i<n;i++)cin>>a[i];
		for(int i = 0;i<n;i++)cin>>b[i];
		sort(a,a+n);sort(b,b+n);
		int p1 = 0,p2 = n-1;//田忌马的两个指针
		int p3 = 0,p4 = n-1;//国王马 
		while(p1<=p2&&p3<=p4){
			if(a[p1]>b[p3]){
				p1++;
				p3++;
				ans++;
			}
			else if(a[p1]<b[p3]){
				p1++;
				p4--;
				ans--;
			}
			else if(a[p2]>b[p4]){
				p2--;
				p4--;
				ans++;
			}
			else if(a[p2]<b[p4]){
				p1++;
				p4--;
				ans--;
			}
			else if(a[p1]<b[p4]){
				p1++;
				p4--;
				ans--;
			}
			else{
				p1++;
				p4--;
			}
		}
		cout<<ans*200<<endl; 
	}
	return 0; 
}