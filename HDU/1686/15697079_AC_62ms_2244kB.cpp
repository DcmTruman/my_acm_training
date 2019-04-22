#include<stdio.h>
#include<string.h>
using namespace std;
const int MAXN=1000000;
char p[MAXN+10],ss[MAXN+10];
int nexta[MAXN+10];

void getnext(char mode[]){
	int i=0,j=-1,mlen;
	nexta[0]=-1;
	mlen=strlen(mode);	
	while(i<mlen){
		while(j!=-1 && mode[j]!=mode[i])
			j=nexta[j];
		nexta[++i]=++j;
	}
	return ;
}

int kmp(char mode[],char str[]){
	int i=0,j=0,ans=0,mlen,nlen;
	mlen=strlen(mode);
	nlen=strlen(str);
    while(i<nlen){
		while(j!=-1 && str[i]!=mode[j]){
			j=nexta[j];
		}
		
		i++; j++;
		if(j==mlen){
			ans+=1;
			j=nexta[j];
		}
	}
	return ans;
}

int main()
{
	int ans,T;
	scanf("%d",&T);
	while(T--){
		scanf("%s %s",p,ss);
		getnext(p);
		ans=kmp(p,ss);
		printf("%d\n",ans);
	}
	return 0;
}