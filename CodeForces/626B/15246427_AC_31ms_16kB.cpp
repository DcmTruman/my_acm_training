#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int abc[5];
int main()
{
	int N;
	char c;
	cin>>N;
	abc[0]=0;
abc[1]=0;
abc[2]=0;
	for(int i = 0;i<N;i++)
	{
		
		cin>>c;
		if(c=='B')abc[0]++;
		else if(c=='G')abc[1]++;
		else if(c=='R')abc[2]++;
	}
	//cout<<abc[0]<<endl;
	//cout<<abc[1]<<endl;
	//cout<<abc[2]<<endl;
	if(abc[0] == N)cout<<"B"<<endl;
	else if(abc[1] == N)cout<<"G"<<endl;
	else if(abc[2] == N)cout<<"R"<<endl;
	else if(N == 2&&abc[0] == 1&&abc[1] == 1)cout<<"R"<<endl;
	else if(N== 2&&abc[1] == 1&&abc[2] == 1)cout<<"B"<<endl;
	else if(N == 2&&abc[0] == 1&&abc[2] == 1)cout<<"G"<<endl;
	else if(N>2&&abc[0] == N-1&&abc[1] == 1)cout<<"GR"<<endl;
	else if(N>2&&abc[0] == N-1&&abc[2] == 1)cout<<"GR"<<endl;
	else if(N>2&&abc[1] == N-1&&abc[2] == 1)cout<<"BR"<<endl;
	else if(N>2&&abc[1] == N-1&&abc[0] == 1)cout<<"BR"<<endl;
	else if(N>2&&abc[2] == N-1&&abc[0] == 1)cout<<"BG"<<endl;
	else if(N>2&&abc[2] == N-1&&abc[1] == 1)cout<<"BG"<<endl;
	else cout<<"BGR"<<endl;
	
	
	
	
} 



