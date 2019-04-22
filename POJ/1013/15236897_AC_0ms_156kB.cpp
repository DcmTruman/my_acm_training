#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <math.h>  
  
/*A-L的阿斯克码为65-76*/  
int val[77];  
  
/* 处理不平衡状态 */  
void work(int len, char wi[], char li[])  
{  
    int j;  
    for (j = 0; j < len; j++)  
    {  
        /* 对重的一边，已经是真的不需要再判断 */  
        if (val[wi[j]] != 10)  
        {  
            val[wi[j]]++;  
        }  
        /* 对轻的一边，已经是真的不需要再判断 */  
        if (val[li[j]] != 10)  
        {  
            val[li[j]]--;  
        }  
    }  
}  
  
int main()  
{  
    char l[3][7], r[3][7], w[3][5];  
    int i, j, n, len, max, maxid;  
  
    /*freopen("1.txt","r",stdin);*/  
  
    scanf("%d", &n);  
    while(n--)  
    {  
        /* 初始化标记数组 */  
        for (i = 65; i < 77; i++)  
        {  
            val[i] = 0;  
        }  
        /* 对每组三次称量进行处理 */  
        for (i = 0; i < 3; i++)  
        {  
            scanf("%s%s%s", l[i], r[i], w[i]);  
            len = strlen(l[i]);  
            /* 如果相等则所有硬币都是真的，置10 */  
            if (w[i][0] == 'e')  
            {  
                for (j = 0; j < len; j++)  
                {  
                    val[l[i][j]] = 10;  
                    val[r[i][j]] = 10;  
                }  
            }  
            /* 如果左边重 */  
            else if (w[i][0] == 'u')  
            {  
                work(len, l[i], r[i]);  
            }  
            /* 如果左边轻 */  
            else if (w[i][0] == 'd')  
            {  
                work(len, r[i], l[i]);  
            }  
        }  
  
        /* 找出哪个硬币被怀疑最多次 */  
        max = maxid = 0;  
        for (i = 65; i < 77; i++)  
        {  
            if (val[i] != 10 && abs(val[i]) > max)  
            {  
                max = abs(val[i]);  
                maxid = i;  
            }  
        }  
  
        /* 输出假币信息 */  
        if (val[maxid] > 0)  
        {  
            printf("%c is the counterfeit coin and it is heavy.\n", maxid);  
        }  
        else  
        {  
            printf("%c is the counterfeit coin and it is light.\n", maxid);  
        }  
    }  
  
    return 0;  
} 