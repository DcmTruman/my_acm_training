#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
ll aa[100020];
ll bb[100020];
ll cc[100020];
ll dd[100020];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%lld",&aa[i]);
	}
	for(int j = 0;j<n;j++){
		scanf("%lld",&bb[j]);
	}
	if(aa[0] != bb[0] || aa[n-1] != bb[n-1]){
		printf("No\n");
		return 0;
	}
	for(int i = 0;i<n-1;i++){
		cc[i] = aa[i+1] - aa[i];
		dd[i] = bb[i+1] - bb[i];
	}
	sort(cc,cc+n-1);
	sort(dd,dd+n-1);
	bool flag = true;
	for(int i = 0;i<n-1;i++){
		if(cc[i] != dd[i]){
			flag = false;
			break;
		}
	}
	if(flag)printf("Yes\n");
	else printf("No\n");
}
