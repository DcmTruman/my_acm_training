#pragma comment(linker, "/STACK:102400000,102400000"  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<cstdlib>  
#include<iostream>  
#include<algorithm>  
#include<vector>  
#include<map>  
#include<queue>  
#include<stack>  
#include<string>  
#include<map>  
#include<set>  
#include<ctime>  
#define eps 1e-6  
#define MAX 1000010  
#define INF 0x3f3f3f3f  
#define LL long long  
#define pii pair<int,int>  
#define rd(x) scanf("%d",&x)  
#define rd2(x,y) scanf("%d%d",&x,&y)  
///map<int,int>mmap;  
///map<int,int >::iterator it;  
using namespace std;  
  
bool isprm[MAX];  
int prm[100000],cnt=0;  
void isprime()  
{  
    memset(isprm,1,sizeof(isprm));  
    isprm[0]=isprm[1]=false;  
    for(int i=2; i<MAX; ++i)  
    {  
        if(isprm[i])  
        {  
            for(int j=2*i; j<MAX; j+=i)  
                isprm[j]=false;  
            prm[cnt++]=i;  
        }  
    }  
}  
int binsear(int tmp)  
{  
    int l=0,r=cnt;  
    while(l<=r)  
    {  
        int mid=(l+r)/2;  
        if (prm[mid] > tmp)  
            r = mid - 1;  
        else  
            l=mid + 1;  
    }  
    for(int i=max(r,0);;i++)  
        if(prm[i]>tmp)  
        return prm[i];  
}  
int main ()  
{  
    isprime();  
    int T,n,Case=1;  
    rd(T);  
    while(T--)  
    {  
        rd(n);  
        LL sum=0,tmp;  
        for(int i=0; i<n; i++)  
        {  
            rd(tmp);  
            sum+=binsear(tmp);  
            //cout<<sum<<' ';  
        }  
        printf("Case %d: %lld Xukha\n",Case++,sum);  
    }  
    return 0;  
} 