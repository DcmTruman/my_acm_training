#include <iostream>  
#include  <cstdio>  
#include <cstring>  
using namespace std;  
int nexta[1006];  
char t[1006],s[1006];  
void getnexta(char s[])  
{  
    memset(nexta,0,sizeof(nexta));  
    int n = strlen(s);  
    int k = -1,j = 0;  
    nexta[0] = -1;  
    while(j < n )  
    {  
  
        if(k == -1 || s[k] == s[j])  
        {  
            nexta[j + 1] = k + 1;  
            j ++;  
            k ++;  
        }  
        else  
        {  
            k = nexta[k];  
        }  
    }  
  
}  
int kmp(char s[],char t[])//t模式串，s母串.此种为返回首次匹配的位置，不能匹配则返回-1.  
{  
    getnexta(t);  
    int ans = 0;  
    int n = strlen(s),m = strlen(t);  
    int i = 0,j = 0;  
    while(i < n && j < m)  
    {  
        if(j == -1 || s[i] == t[j])  
        {  
            i ++;  
            j ++;  
        }  
        else  
        {  
            j = nexta[j];  
        }  
        if(j == m)//根据题目要求改变  
        {  
            ans ++;  
            j = 0;  
        }  
    }  
    return ans;  
}  
int main()  
{  
   // freopen("in.txt","r",stdin);  
    while(1)  
    {  
        scanf("%s",s);  
        if(strcmp(s,"#") == 0)  
            break;  
        scanf("%s",t);  
        printf("%d\n",kmp(s,t));  
    }  
    return 0;  
}  