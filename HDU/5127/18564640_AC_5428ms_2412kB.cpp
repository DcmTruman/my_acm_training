#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<functional>
#include"stdio.h"
using namespace std;

int main() 
{
 ios::sync_with_stdio(false);
 vector<pair<long long int, long long int> > candy;
 vector<pair<long long int, long long int> >::iterator iter;

 long long  n;
 long long  i;
 long long  mx, m;
 long long  x, y;
 int t;



 while (~scanf("%lld",&n)&&n)
 {
  candy.clear();

  for (i = 0; i < n; i++)
  {
   scanf("%d", &t); scanf("%lld", &x); scanf("%lld", &y);
   
   switch (t)
   {
   case 1:
    candy.push_back(pair<long long int, long long int>(x, y));
    break;

   case -1:
	for(iter = candy.begin();iter!=candy.end();iter++){
		if(iter->first == x && iter->second == y){
			candy.erase(iter);
			break;
		}
	}
    break;

   case 0:
    mx = candy.begin()->first*x + candy.begin()->second*y;
    for (vector<pair<long long int, long long int> >::iterator it = candy.begin(); it != candy.end(); it++)
    {
     m = it->first*x + it->second*y;
     if (m > mx)
     {
      mx = m;
     }
    }
    printf("%lld\n", mx);
    break;

   default:
    break;
   }
  }
 }


}
