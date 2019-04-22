    #include <stdio.h>  
    #include <string.h>  
      
    int l = 0,flag = 0;  
      
    struct Node  
    {  
        char head,end;  
    } c[10000];  
    int vis[10000];  
      
    void dfs(char ch)  
    {  
        int i;  
        if(ch == 'm')  
            flag = 1;  
        if(flag)  
            return;  
        for(i = 0; i<l; i++)  
        {  
            if(vis[i])  
                continue;  
            if(c[i].head == ch)  
            {  
                vis[i] = 1;  
                dfs(c[i].end);  
                vis[i] = 0;  
            }  
        }  
    }  
      
    int main()  
    {  
        char s[100];  
        int i;  
        while(~scanf("%s",s))  
        {  
            if(!strcmp(s,"0"))  
                continue;  
            l = 0;  
            c[l].head = s[0];  
            c[l].end = s[strlen(s)-1];  
            l++;  
            while(scanf("%s",s),strcmp(s,"0"))  
            {  
                c[l].head = s[0];  
                c[l].end = s[strlen(s)-1];  
                l++;  
            }  
            flag = 0;  
            for(i = 0; i<l; i++)  
            {  
                if(c[i].head == 'b')  
                {  
                    memset(vis,0,sizeof(vis));  
                    vis[i] = 1;  
                    dfs(c[i].head);  
                }  
                if(flag)  
                    break;  
            }  
            if(flag)  
                printf("Yes.\n");  
            else  
                printf("No.\n");  
        }  
      
        return 0;  
    }  