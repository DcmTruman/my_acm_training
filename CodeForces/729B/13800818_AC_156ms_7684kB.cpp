    #include <iostream>  
    #include <cstdio>  
    #include <cstring>  
    #include <algorithm>  
    using namespace std;  
    const int maxn = 1e3 + 5;  
    int matrix[maxn][maxn], book1[maxn], book2[maxn];  
    int main()  
    {  
            int n, m;  
            scanf("%d%d", &n, &m);  
            int ans = 0;  
            for(int i = 1; i <= n; i++)  
                for(int j = 1; j <= m; j++)  
            {  
                scanf("%d", &matrix[i][j]);  
                if(matrix[i][j]) book1[i] = 1, book2[j] = 1;  
                else  
                {  
                    if(book1[i]) ans++;  
                    if(book2[j]) ans++;  
                }  
            }  
            memset(book1, 0, sizeof(book1));  
            memset(book2, 0, sizeof(book2));  
            for(int i = n; i >= 1; i--)  
                for(int j = m; j >= 1; j--)  
            {  
                if(matrix[i][j]) book1[i] = book2[j] = 1;  
                else  
                {  
                    if(book1[i]) ans++;  
                    if(book2[j]) ans++;  
                }  
            }  
            printf("%d\n", ans);  
        return 0;  
    }  