#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<set>
#include<functional>
#include<sstream>
#include<algorithm>
#include <string.h>
#include"stdio.h"
using namespace std;

long long  ti[100020][13];
long long  most[100020][13];

int main()
{
 long long n,tmax;
 long long x, t;
 long long i, j;

 while (1)
 {
  memset(ti, 0, sizeof(ti));
  memset(most, 0, sizeof(ti));
  scanf("%lld", &n);
  //scanf("%lld", &n);
  if (n == 0)
   break;
  tmax = 0;
  for (; n > 0; n--)
  {
   //scanf_s("%lld", &x);scanf_s("%lld", &t);
   scanf("%lld", &x);scanf("%lld", &t);
   ti[t][x]++;
   if (t > tmax)
    tmax = t;
  }


  for (i = tmax; i >= 0; i--)
  {
   for (j = 0; j < 11; j++)
   {
     if(j==0)
      most[i][j]= max(most[i + 1][j], most[i + 1][j + 1]) + ti[i][j];
     else
      most[i][j] = max(max(most[i + 1][j - 1], most[i + 1][j]),  most[i + 1][j + 1]) + ti[i][j];
   }
   /*for (int x = 0; x <= tmax; x++)
   {
    for (int y = 0; y < 13; y++)
     cout << most[x][y] << " ";
    cout << endl;
   }
   cout << endl;*/
  }
  printf("%lld\n",most[0][5]);
 }
 //getchar(); getchar(); getchar(); getchar();
}
