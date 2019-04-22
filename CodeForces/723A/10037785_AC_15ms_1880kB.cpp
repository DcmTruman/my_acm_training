#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int add[3],bdd[3];
	for (int i=0;i<3;i++){
		cin>>add[i];
	}
	for (int i = 0;i<3;i++){
		bdd[i] = abs(add[0]-add[i])+abs(add[1]-add[i])+abs(add[2]-add[i]);
	}
	sort(bdd,bdd+3);
	cout << bdd[0];
}