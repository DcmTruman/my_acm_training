#include<iostream>
#include<algorithm>


using namespace std;

const int maxn = 4020;

int A[maxn],B[maxn],C[maxn],D[maxn];

int ab[16000020],cd[16000020];

int main()
{
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>A[i]>>B[i]>>C[i]>>D[i];
	}
	int c1 = 0;
	int c2 = 0;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			ab[c1++] = A[i]+B[j];
			cd[c2++] = C[i]+D[j];
		}
	}
	sort(ab,ab+c1);
	sort(cd,cd+c2);
	
	bool flag = false;
	int ans = 0;
	for(int i = 0;i<c1;i++)
	{
		int t = ab[i];
		
		ans += upper_bound(cd,cd+c2,-t)-cd -(lower_bound(cd,cd+c2,-t)-cd);

	}
	cout<<ans<<endl;
	
return 0;
	
}