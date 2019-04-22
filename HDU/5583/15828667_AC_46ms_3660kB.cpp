#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char ss[100005];
long long left[100005],right[100005];
int lst[100005],nxt[100005];
int main()
{
	int T;
	long long pst,n;
	long long ans,tmp;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%s",ss);
		n=strlen(ss);
		pst=-1; left[0]=0;
		for(long long i=1;i<=n;i++){
			if(pst==-1){
				left[i]=1; pst=i;
				lst[i]=0;
			}else if(ss[i-1]==ss[pst-1]){
				left[i]=left[pst-1]+(i-pst+1)*(i-pst+1);
				lst[i]=pst-1;
			}else{
				left[i]=left[i-1]+1; pst=i;
				lst[i]=i-1;
			}
		}
		pst=-1; right[n+1]=0;
		for(long long i=n;i>=1;i--){
			if(pst==-1){
				right[i]=1; pst=i;
				nxt[i]=n+1;
			}else if(ss[i-1]==ss[pst-1]){
				right[i]=right[pst+1]+(pst-i+1)*(pst-i+1);
				nxt[i]=pst+1;
			}else{
				right[i]=right[i+1]+1; pst=i;
				nxt[i]=i+1;
			}
		}
		/*for(int i=0;i<=n+1;i++){
			printf("[%d] %lld %lld %d %d\n",i,left[i],right[i],lst[i],nxt[i]);
		}*/
		ans=left[n];
		for(long long i=1;i<=n;i++){
			tmp=0;
			if(i>=2 && i<n && ss[i-1]!=ss[i-2] && ss[i-1]!=ss[i]){
				tmp=left[lst[i-1]]+(nxt[i+1]-lst[i-1]-1)*(nxt[i+1]-lst[i-1]-1)+right[nxt[i+1]];
			}else if(i>=2 && ss[i-1]!=ss[i-2]){
				tmp=left[lst[i-1]]+(i-lst[i-1])*(i-lst[i-1])+right[i+1];
			}else if(i<n && ss[i-1]!=ss[i]){
				tmp=right[nxt[i+1]]+(nxt[i+1]-i)*(nxt[i+1]-i)+left[i-1];
			}else{
				tmp=left[i-1]+1+right[i+1];
			}
			//printf("pst %d %lld\n",i,tmp);
			ans=max(tmp,ans);
		}
		printf("Case #%d: %lld\n",t,ans);
	}
	return 0;
}
