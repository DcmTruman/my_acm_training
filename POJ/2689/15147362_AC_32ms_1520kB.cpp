#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll maxn = 46500;
const ll Maxn = 1000020;
const ll INF = 0x3f3f3f3f;
ll gcd(ll a,ll b){
	//cout<<a<<" "<<b<<endl;
	return (b!=0)?gcd(b,a%b):a;
}
bool isp[Maxn];
ll pr[maxn];
ll pr2[Maxn];
ll k1 = 0;
ll k2 = 0;


void init1()
{
	memset(isp,1,sizeof(isp));
	for(ll i = 2;i<maxn;i++)
	{
		if(isp[i])
		{
			pr[k1++] = i;
			ll cnt = 2;
			for(ll j = 2 * i; j <= maxn; j += i)
        	{
            	isp[j] = false;
			}
		}
	}
}

void init2(ll l,ll r)
{
	memset(isp,1,sizeof(isp));
	if(l<2)l = 2;
	k2 = 0;
	for(ll i = 0;i<k1&&pr[i]*pr[i]<=r;i++)
	{
		ll temp = l/pr[i];
		
		if(temp*pr[i]<l)temp++;
		
		if(temp<2)temp = 2;
		
		for(ll j = temp;(ll)j*pr[i]<=r;j++)
		{
			isp[j*pr[i]-l] = false;
		}
	}
	for(ll i = 0;i<=r-l;i++)
	{
		if(isp[i])pr2[k2++] = i+l;
	}
}

int main()
{
	ll l,r;
	ll mn,mx;
	ll aa,bb,cc,dd;
	init1();
	while(scanf("%I64d%I64d",&l,&r)!=EOF)
	{
		init2(l,r);
		mn = INF;
		mx = -1;
		if(k2<2)
		{
			printf("There are no adjacent primes.\n");
            continue;
		}
		for(ll i = 1;i<k2&&pr2[i]<=r;i++)
		{
			ll d = pr2[i]-pr2[i-1];
			if(d<mn)
			{
				aa = pr2[i-1];
				bb = pr2[i];
				mn = d;
			}
			if(d>mx)
			{
				cc = pr2[i-1];
				dd = pr2[i];
				mx  = d;
			}
		}
		printf("%I64d,%I64d are closest, %I64d,%I64d are most distant.\n", aa, bb, cc, dd);
		
	}
	return 0;
} 
