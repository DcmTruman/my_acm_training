#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
struct node
{
  int x,y;
}a[50100];
int cmp(node a,node b)
{
 if(a.x!=b.x)
    return a.x<b.x;
 return a.y<b.y;
}
int s[50100],e[50100];
int main()
{
 int n;
 while(cin>>n)
 {
   int cnt=0;
   for(int i=0;i<n;i++)
     cin>>a[i].x>>a[i].y;
   sort(a,a+n,cmp);
   s[cnt]=a[0].x;
   e[cnt]=a[0].y;
   for(int i=1;i<n;i++)
   {
     if(a[i].x>e[cnt])
     {
       cnt++;
       s[cnt]=a[i].x;
       e[cnt]=a[i].y;
     }
     else 
     {
       if(a[i].y>e[cnt])
       e[cnt]=a[i].y;
     }
   }
  for(int i=0;i<=cnt;i++)
  {
    cout<<s[i]<<" "<<e[i]<<endl;
  }
 }
 return 0;
}