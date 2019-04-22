    #include<cstdio>  
    #include<cstring>  
    #include<algorithm>  
    using namespace std;  
    inline int GCD(int a,int b)  
    {  
        int t;  
        if(b>a)  
        {  
            t=a;  
            a=b;  
            b=t;  
        }  
        while(b)  
        {  
            t=b;  
            b=a%b;  
            a=t;  
        }  
        return a;  
    }  
      
    int main()  
    {  
        int a[100001],b[100001];  
        int t,n,i,j;  
        scanf("%d",&t);  
        while(t--)  
        {  
            scanf("%d",&n);  
            for(i=0; i<n; i++)  
            {  
                scanf("%d",&a[i]);  
            }  
            int y,M=0;  
            b[0]=b[1]=-1;  
            for(j=0; j<n; j++)  
            {  
                y=a[0];  
                if(j==0)  
                    y=a[1];  
      
                for(i=0; i<n; i++)  
                {  
                    if(i==j)  
                        continue;  
                    y=GCD(a[i],y);  
                    if(y<=M)  
                        break;  
      
                    if(i==j+1)//对比记录的共因子大小是否有变化，没变化则不用继续，节约时间  
                    {  
                        if(y==b[i])  
                        break;  
                    }  
                    if(i==j+2)//记录上一组处理到这个位置的共因子大小  
                    {  
                        b[i]=y;  
                    }  
                }  
                if(M<y)  
                    M=y;  
            }  
            printf("%d\n",M);  
        }  
        return 0;  
    }  