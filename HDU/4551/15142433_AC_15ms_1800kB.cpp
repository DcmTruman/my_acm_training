#include<iostream>
#include<stdio.h>
using namespace std;


int gcd(int a,int b){
	//cout<<a<<" "<<b<<endl;
	return (b!=0)?gcd(b,a%b):a;
}
int aa[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int isrun(int x)
{
	if((x%4==0&&x%100!=0)||x%400==0)
	return 1;
	return 0;
}
int main()
{
	int a,b,c;
	int e;
	int T;
	int TT;
	cin>>T;
	TT = T;
	while(T--){
		int cnt = 0;
		cin>>a>>b>>e;
		if(isrun(e))aa[1] = 29;
		int d;
		int c = a*b;
		for(int i = 1;i<=12;i++)
		{
			if(c%i == 0&&gcd(i,c/i) == a&&c/i<=aa[i-1])
			{
				d = i;
				cnt++;
			}
		}
		if(cnt == 1)
		{
			printf("Case #%d: %d/%02d/%02d\n",TT-T,e,d,c/d);
		}
		else if(cnt == 0)
		{
			cout<<"Case #"<<TT-T<<": -1"<<endl;
		}
		else
		{
			cout<<"Case #"<<TT-T<<": 1"<<endl;
		}
	}	
} 















