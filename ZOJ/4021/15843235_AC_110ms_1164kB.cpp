#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char ss[500020];
char stack[500020];
int num;
char ops(char x){
	return x=='T'? 'F':'T';
}
char calc(char x,char t,char y){
	if(t=='&'){
		if(x=='T'&&y=='T') return 'T';
		if(x=='X'||y=='X') return 'X';
		if(x=='T'||y=='T') return 'F';
		return 'X';
	}else if(t=='|'){
		if(x=='T'||y=='T') return 'T';
		if(x=='F'||y=='F') return 'F';
		return 'X';
	}
}

int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%s",ss);
		n=strlen(ss);
		num=0; stack[0]='(';
		ss[n]=')'; ss[n+1]='\0';
		for(int i=0;i<=n;i++){
			stack[++num]=ss[i];
			if(stack[num]==')'){
				num-=2;
				if(stack[num+1]=='('){
					stack[num+1]='\0'; continue;
				}
				while(stack[num]!='('){
					if(stack[num]=='|'){
						stack[num-1]=calc(stack[num-1],'|',stack[num+1]);
						num-=2;
					}else{
						break;
					}
				}
				if(stack[num]=='('){
					stack[num]=stack[num+1];
					if(stack[num]=='X' && num!=0) stack[num]='F';
				}
			}
			while(stack[num]=='T'||stack[num]=='F'||stack[num]=='X'){
				if(stack[num-1]=='!'){
					stack[num-1]=ops(stack[num]);
					num-=1;
				}else{
					break;
				}
			}
			while(stack[num]=='T'||stack[num]=='F'||stack[num]=='X'){
				if(stack[num-1]=='&'){
					stack[num-2]=calc(stack[num-2],'&',stack[num]);
					num-=2;
				}else{
					break;
				}
			}
			stack[num+1]='\0';
			//printf(">> %s\n",stack);
		}
		//printf("%s\n",stack);
		if(stack[0]=='T'){
			printf("0\n");
		}else if(stack[0]=='F'){
			printf("1\n");
		}else if(stack[0]=='X'){
			printf("2\n");
		}else{
			printf("1\n");
		}
	}
	return 0;
}
