#include <iostream>
#include  <cstdio>
#include <cstring>
using namespace std;
int nexta[400020];
char s[400020];
int add[400020];
void getnexta(char s[])
{
    memset(nexta,0,sizeof(nexta));
    int n = (int)strlen(s);
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

int main()
{
    while(scanf("%s",s)!=EOF)
    {
        getnexta(s);
        memset(add,0,sizeof(add));
        int len = (int)strlen(s);
        int t = 0;
        for(int i = len;i!=-1;i = nexta[i])
        {
            add[t++] = i;
        }
        for(int i = t-2;i>=0;i--)
        {
            if(i)cout<<add[i]<<" ";
            else cout<<add[i]<<endl;
        }
    }
}