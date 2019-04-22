    #include <stdio.h>  
    #include <string.h>  
    #include <algorithm>  
    using namespace std;  
      
    int hash[105];  
      
    int main()  
    {  
        int n,i,a;  
        while(~scanf("%d",&n))  
        {  
            int flag = 0;  
            memset(hash,0,sizeof(hash));  
            for(i = 0; i<n; i++)  
            {  
                scanf("%d",&a);  
                hash[a]++;  
                if(a == 25)  
                    continue;  
                else if(a == 50)  
                {  
                    if(hash[25])  
                    {  
                        hash[25]--;  
                        continue;  
                    }  
                    else  
                        flag = 1;  
                }  
                else if(a == 100)  
                {  
                    if(hash[25] && hash[50])  
                    {  
                        hash[25]--;  
                        hash[50]--;  
                        continue;  
                    }  
                    else if(hash[25]>=3)  
                    {  
                        hash[25]-=3;  
                        continue;  
                    }  
                    else  
                        flag = 1;  
                }  
            }  
            if(flag)  
                printf("NO\n");  
            else  
                printf("YES\n");  
        }  
      
        return 0;  
    }  