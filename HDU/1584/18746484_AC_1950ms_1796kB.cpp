#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int fa[12];
void init()
{
	for(int i = 0;i<12;i++)fa[i] = i;
}

int find(int x){
	return (fa[x] == x)?x : fa[x] = find(fa[x]);
}

void unn(int x,int y)
{
	int xx = find(x);
	int yy = find(y);
	if(xx > yy)swap(xx,yy);
	fa[xx] = yy;
}

struct arr{
	int nnn[12];
};

int calc(arr num , arr nn)
{
	int ret = 0;
	int c1,c2;
	for(int i = 0;i<9;i++){
		int now = num.nnn[i];
		int nowx = find(now);
		int nowy = find(now + 1);
		c1 = nn.nnn[nowx];
		c2 = nn.nnn[nowy];
		ret += abs(c1 - c2);
		nn.nnn[nowx] = nn.nnn[nowy];
		fa[nowx] = nowy;
	}
	return ret;
}
int main()
{
	int T;
	cin >> T;
	int nT[12];
	int nn[12] = {1,2,3,4,5,6,8,9,7};
	arr t1,t2;
	while(T--)
	{
		int dis = 0x3f3f3f3f;
		for(int i = 0;i<10;i++){
			cin >> nT[i];
			t1.nnn[nT[i]] = i;	
		}
		arr num;
		for(int i = 0;i<9;i++)num.nnn[i] = i + 1;
	
		do
		{
			init();
			int res = calc(num,t1);
		//	if(dis > res){
		//		for(int i = 0;i<9;i++)cout << num.nnn[i] << " ";
		//		cout << res << endl;
		//	}
			dis = min(dis,res);
		}while(next_permutation(num.nnn,num.nnn+9)); 
		cout << dis << endl;
	}
return 0;
}


