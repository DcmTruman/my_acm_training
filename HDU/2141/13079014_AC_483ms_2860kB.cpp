    #include <iostream>  
    #include <cstdio>  
    #include <cstring>  
    #include <algorithm>  
      
    using namespace std;  
      
    int a[550];  
    int b[550];  
    int c[550];  
    int d[300000];  
      
    int main()  
    {  
        int l,n,m;  
        int cnt = 0;  
        while(scanf("%d%d%d",&l,&n,&m) != EOF)  
        {  
            for(int i = 0;i < l;i++)  
            {  
                scanf("%d",a + i);  
            }  
            for(int i = 0;i < n;i++)  
            {  
                scanf("%d",b + i);  
            }  
            for(int i = 0;i < m;i++)  
            {  
                scanf("%d",c + i);  
            }  
              
            int k = 0;  
            for(int i = 0;i < l;i++)  
            {  
                for(int j = 0;j < n;j++)  
                {  
                    d[k++] = a[i] + b[j];  
                }  
            }  
              
            sort(d,d + k);  
            int num;  
            int s;  
            scanf("%d",&s);  
            printf("Case %d:\n",++cnt);  
            for(int i = 0;i < s;i++)  
            {  
                scanf("%d",&num);  
                bool flag = false;  
                for(int j = 0;j < m;j++)  
                {  
                    int x = num - c[j];  
                    int y = lower_bound(d,d + k,x) - d;  
                    if(y != k && d[y] == x)  
                    {  
                        flag = true;  
                        break;  
                    }  
                }  
                if(flag)  
                {  
                    printf("YES\n");  
                }  
                else  
                {  
                    printf("NO\n");  
                }  
            }  
        }  
          
        return 0;  
    }  