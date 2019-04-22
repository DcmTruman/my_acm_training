#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
using namespace std;


bool check(int a,int b){
	int aa[15];
	memset(aa,0,sizeof(aa));
    if(b > 98765) return false;
    for(int i = 0;i < 5;i++)
	{       
        aa[a % 10]++;aa[b % 10]++;
        a /= 10;b /= 10;
    }

    for(int i = 0;i < 10;i++){
        if(aa[i] != 1) return false;
    }
    return true;
}

int main()
{
	int N ;
	int fk = 0;
	while(cin>>N&&N)
	{
		if(fk++>0)cout<<endl;
		bool flag = false;
		for(int i = 1234;i<99999;i++)
		{
			if(check(i,i*N))
			{
				flag = true;
				printf("%05d / %05d = %d\n",N*i,i,N);
			}
		}
		if(!flag)printf("There are no solutions for %d.\n",N);
	}
}