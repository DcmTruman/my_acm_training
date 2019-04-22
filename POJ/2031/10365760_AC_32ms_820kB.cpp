
#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<cmath>  
using namespace std;  
#define N 1005  
  
struct stud{  
double x,y,z,r;  
}s[N];  
  
struct studd{  
int a,b;  
double len;  
}f[N*N];  
  
int n,k;  
int father[N];  
  
  
int cmp(studd a,studd b)  
{  
    return a.len<b.len;  
}  
  
int cha(int x)  
{  
    if(x!=father[x])  
        father[x]=cha(father[x]);  
    return father[x];  
  
}  
  
int main()  
{  
    int i,j;  
    while(scanf("%d",&n),n)  
    {  
        for(i=0;i<n;i++)  
            scanf("%lf%lf%lf%lf",&s[i].x,&s[i].y,&s[i].z,&s[i].r);  
  
        k=0;  
  
        for(i=0;i<n;i++)  
            for(j=i+1;j<n;j++)  
        {  
            f[k].a=i;  
            f[k].b=j;  
            double x=s[i].x-s[j].x;  
            double y=s[i].y-s[j].y;  
            double z=s[i].z-s[j].z;  
            double ll=sqrt(x*x+y*y+z*z)-s[i].r-s[j].r;  
  
            if(ll<0)  
                f[k].len=0;  
            else  
                f[k].len=ll;  
            k++;  
        }  
  
        sort(f,f+k,cmp);  
  
        for(i=0;i<=n;i++)  
            father[i]=i;  
  
        int num=1;  
  
        double ans=0;  
  
        for(i=0;i<k;i++)  
        {  
            int aa=cha(f[i].a);  
            int bb=cha(f[i].b);  
            if(aa!=bb)  
            {  
                father[aa]=bb;  
                ans+=f[i].len;  
                num++;  
                if(num==n)  
                    break;  
            }  
        }  
  
        printf("%.3f\n",ans);  
    }  
    return 0;  
}  