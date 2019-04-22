#include<iostream>  
#include<cstring>  
using namespace std;  
  
int a[1000001];  
  
int main()  
{  
    int n,m;  
    while(cin>>n>>m)  
    {  
        int i,j,p;  
        int max=-500001;  
        memset(a,0,sizeof(a));  
        for(i=0;i<n;i++)  
        {  
            scanf("%d",&p);  
            if(max<p)   max=p;  
            a[p+500000]=1;  
        }  
          
        for(i=max+500000;m>=1;i--)  
        {  
            if(a[i]==1)   
            {  
                printf("%d",i-500000);  
                if(m==1)     
                {  
                    cout<<endl;  
                }  
                else   cout<<" ";  
                m--;  
            }  
        }  
    }  
      
    return 0;  
}  