#include <iostream>
#include  <cstdio>
#include <cstring>
using namespace std;
int nexta[10020];
int n,m;
int t[10020],s[1000020];
void getnexta(int s[])
{
    memset(nexta,0,sizeof(nexta));
    int k = -1,j = 0;
    nexta[0] = -1;
    while(j < m )
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
int kmp(int s[],int t[])//t模式串，s母串.此种为返回首次匹配的位置，不能匹配则返回-1.
{
    getnexta(t);
    int ans = -1;
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
            ans = i+1-j;
            return ans;
        }
    }
    return ans;
}
int main()
{
    int Case;
    cin>>Case;
    while(Case--)
    {
        cin>>n>>m;
        for(int i =0;i<n;i++)cin>>s[i];
        for(int i =0;i<m;i++)cin>>t[i];
        cout<<kmp(s,t)<<endl;
    }
    return 0;
}
