#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct _FFF
{
	int start;
	int end;
}FFF;
FFF ADD[120];
bool cmp(FFF A, FFF B)
{
	return A.end<B.end;
}
int N;
int main()
{
	cin>>N;
	while(N!=0)
	{
	int END;
	int num = 1;
	for(int i=0;i<N;i++)
	{
		int a,b;
		cin>>a>>b;
		FFF temp = {a,b};
		ADD[i] = temp;
	}
	sort(ADD,ADD+N,cmp);
	END = ADD[0].end;
	for(int j =1;j<N;j++)
	{
		if(ADD[j].start>=END){
			END = ADD[j].end;
			num++;
		}
	}
	cout<<num<<endl;
	cin>>N;
	}

}
