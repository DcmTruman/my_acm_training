#include<iostream>
#include<stdio.h>
using namespace std;

int pre[50020][2];
int rankk[50020];

int find_pre(int x)
{
 int anum;
 if (pre[x][0] == x) {
  return x;
 }
 anum = pre[x][0];
 pre[x][0] = find_pre(pre[x][0]);
 pre[x][1] = (pre[x][1] + pre[anum][1])% 3;
 return pre[x][0];
}

bool is_samee(int x, int y)      
{
 return find_pre(x) == find_pre(y);  
}

void unite(int x, int y,int num)
{
 int rootx, rooty;
 rootx = find_pre(x);
 rooty = find_pre(y);
 if (rootx == rooty) {
  return;
 }
 if (rankk[rootx] > rankk[rooty]) {
  pre[rooty][0] = rootx;
  if (num == 1)
  {
   pre[rooty][1] = (pre[x][1]-pre[y][1])%3;
   if (pre[rooty][1] < 0)
    pre[rooty][1] = pre[rooty][1] + 3;
   
  }
  else
  {
   pre[rooty][1] = (pre[x][1] - pre[y][1]+1)%3;
   if (pre[rooty][1] < 0)
    pre[rooty][1] = pre[rooty][1] + 3;
   
  }
 }
 else {
  if (rankk[rootx] == rankk[rooty]) {
   rankk[rooty]++;
  }
  pre[rootx][0] = rooty;
  if (num == 1)
  {
   pre[rootx][1] = (pre[y][1] - pre[x][1])%3;
   if (pre[rootx][1] < 0)
    pre[rootx][1] = pre[rootx][1] + 3;
   
  }
  else
  {
   pre[rootx][1] = (pre[y][1] - pre[x][1] - 1)%3;
   if (pre[rootx][1] < 0)
    pre[rootx][1] = pre[rootx][1] + 3;
  }
 }
}

int main()
{
  int n;
  int k;
  int i;
 int num;
  int x, y;
  int count=0;

 //cin >> n >> k;
scanf("%d%d",&n,&k);
 for (i = 0; i < n; i++)
 {
  pre[i][0] = i;
  pre[i][1] = 0;
  rankk[i] = 1;
  
 }
 for (i = 0; i < k; i++)
 {
  //cin >> num >> x >> y;
scanf("%d%d%d",&num,&x,&y);
  if (x > n || y > n||(num==2&&x==y))
  {
   count++;
  }
  else{
   x = x - 1; y = y - 1;
   if (num == 1)
   {
    if (is_samee(x, y))
    {
     if (pre[x][1] != pre[y][1])
      count++;

    }
    else
     unite(x, y, num);
   }
   else
   {
    if (is_samee(x, y))
    {
     if (!(pre[x][1] - pre[y][1]== -1 || pre[x][1] - pre[y][1] == 2))
      count++;
    }
    else
     unite(x, y, num);
   }
  }
 }  

 //cout << count;
printf("%d\n",count);

 return 0;
}