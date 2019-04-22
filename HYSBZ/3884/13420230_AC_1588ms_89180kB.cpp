#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long lol;
const int N=1e7;
lol ans;
int prime[N+5],phi[N+5],tot;
bool vis[N+5];
void pre()
{int i,j;
  phi[1]=0;
  for (i=2;i<=N;i++)
    {
      if (vis[i]==0)
    {
      ++tot;
      prime[tot]=i;
      phi[i]=i-1;
    }
      for (j=1;j<=tot;j++)
    {
      if (1ll*i*prime[j]>N) break;
      vis[i*prime[j]]=1;
      if (i%prime[j]==0)
        {
          phi[i*prime[j]]=phi[i]*prime[j];
          break;
        }
      else  phi[i*prime[j]]=phi[i]*(prime[j]-1);
    }
    }
}
lol qpow(lol x,lol y,lol p)
{
  lol res=1;
  while (y)
    {
      if (y&1) res=res*x%p;
      x=x*x%p;
      y/=2;
    }
  return res;
}
lol f(lol p)
{
  if (phi[p]<=2) return qpow(2,phi[p],p);
  return qpow(2,f(phi[p])+phi[p],p);
}
int main()
{lol p;
  int T;
  pre();
  cin>>T;
  while (T--)
    {
      scanf("%lld",&p);
      ans=qpow(2,f(phi[p])+phi[p],p);
      printf("%lld\n",ans);
    }
}