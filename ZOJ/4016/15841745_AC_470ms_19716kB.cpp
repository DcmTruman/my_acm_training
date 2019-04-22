#include<stdio.h>
#include<string.h>
using namespace std;
const int MAXN=1000000;
int a[MAXN+10];
int link[MAXN+10];

typedef struct Stack{
	int size;
	int pst_last,pst_bottom;
	Stack(){
		size=0; pst_last=-1; pst_bottom=-1;
	}
	void push(int pst){
		if(size==0){
			pst_bottom=pst;
		}
		link[pst]=pst_last;
		pst_last=pst;
		size+=1;
	}
	long long top(){
		if(size>0) return a[pst_last];
		else return -1;
	}
	int pop(){
		int pst_tmp=pst_last;
		if(size>0){
			pst_last=link[pst_last];
			size-=1;
		}
		return pst_tmp;
	}
	void init(){
		size=0; pst_last=-1; pst_bottom=-1;
	}
	/*void output(){
		int pst=pst_last;
		for(int i=0;i<size;i++){
			printf("%lld <- ",a[pst]);
			pst=link[pst];
		}
		printf("[#]\n");
	}*/
}Stack;

Stack stk[MAXN+10];

int main()
{
	int T,n,q,m,cmd,s,t,tmp;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&q);
		m=0;
		for(int i=0;i<=n;i++){
			stk[i].init();
		}
		while(q--){
			scanf("%d",&cmd);
			if(cmd==1){
				scanf("%d %d",&s,&a[m++]);
				stk[s].push(m-1);
			}else if(cmd==2){
				scanf("%d",&s);
				if(stk[s].size==0){
					printf("EMPTY\n");
				}else{
					tmp=stk[s].pop();
					printf("%d\n",a[tmp]);
				}
			}else if(cmd==3){
				scanf("%d %d",&s,&t);
				if(stk[t].size!=0){
					link[stk[t].pst_bottom]=stk[s].pst_last;
					stk[s].pst_last=stk[t].pst_last;
					if(stk[s].size==0){
						stk[s].pst_bottom=stk[t].pst_bottom;
					}
					stk[s].size+=stk[t].size;
					stk[t].size=0;
					stk[t].pst_last=-1;
				}
			}
			/*printf("DEBUG:\n");
			for(int i=1;i<=n;i++){
				printf("[#%d] Top:%d Bottom %d | : ",i,stk[i].pst_last,stk[i].pst_bottom);
				stk[i].output();
			}*/
		}
	}
	return 0;
}