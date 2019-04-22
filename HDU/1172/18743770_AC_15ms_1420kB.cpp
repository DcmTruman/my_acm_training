#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<cstring>
using namespace std;


struct num{
	int nn[4];
};

num gs[120];
int aa[120];
int bb[120];
int n;
int vis1[10];
int vis2[10];

bool isok(num now,num gus,int a,int b)
{
	int cnt1 = 0,cnt2 = 0;
	for(int i = 0;i<10;i++)vis1[i] = 0,vis2[i] = 0;
	for(int i = 0;i<4;i++)
	{
		vis1[now.nn[i]] ++ ;
		vis2[gus.nn[i]] ++ ;
		if(now.nn[i] == gus.nn[i]) cnt2 ++;
	}
	for(int i = 0;i<10;i++)cnt1 += min(vis1[i],vis2[i]);
	if(cnt1 == a && cnt2 == b)return true;
	else return false;
}

bool check(num now)
{
	bool flag = true;
	for(int i = 0;i<n;i++)
	{
		if(!isok(now,gs[i],aa[i],bb[i])){
			flag = false;
			break;
		}
	}
	if(flag)return true;
	else return false;
}

void show(num now)
{
	for(int i = 0;i<4;i++)cout << now.nn[i];
	cout << endl;
}
int main()
{
	while(~scanf("%d" , &n) && n)
	{
		for(int i = 0;i<n;i++)
		{
			int a,b,c;
			cin >> a >> b >> c;
			gs[i].nn[0] = a / 1000;
			gs[i].nn[1] = (a % 1000) / 100;
			gs[i].nn[2] = (a % 100) / 10;
			gs[i].nn[3] = a % 10;
			aa[i] = b;
			bb[i] = c;
		}
		num temp;
		num fin;
		int flag = 0;
		for(int i = 1;i<10;i++){
			temp.nn[0] = i;
			for(int j = 0;j<10;j++){
				temp.nn[1] = j;
				for(int k = 0;k<10;k++){
					temp.nn[2] = k;
					for(int q = 0;q<10;q++){
						temp.nn[3] = q;
						if(check(temp)){
							fin = temp;
							flag++;
						}
					}
				}
			}
		}
		if(flag == 1)show(fin);
		else cout << "Not sure\n";
		
	}
}
