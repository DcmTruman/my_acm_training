#include <iostream>
#include  <cstdio>
#include <cstring>
using namespace std;
int nexta[1000020];
char s[1000020];
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

int main()
{
    while(scanf("%s",s)!=EOF&&s[0]!='.')
    {
        int len = strlen(s);
        int maxtime = 1;
        getnexta(s);
        if(len%(len-nexta[len])==0)
            maxtime=len/(len-nexta[len]);
        cout<<maxtime<<endl;
    }
    return 0;
}