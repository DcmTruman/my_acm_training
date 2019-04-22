    #include<iostream>  
    using namespace std;  
    int year[1000005];  
    void YE()  
    {  
        int j = 1;  
        for (int i = 4; i < 1000005;)  
        {  
            if (i % 4 == 0&&i%100!=0)  
            {  
                year[j] = i;  
                //cout << year[j] << endl;  
                j++;  
            }  
            if (i%400==0)  
            {  
                year[j] = i;  
                //cout << year[j] << endl;  
                j++;  
            }  
            i = i + 4;  
        }  
    }  
    int main()  
    {  
        YE();  
        int n, y, x;  
        int ed;  
        cin >> n;  
        while (n--)  
        {  
            cin >> y >> x;  
            for (int i = 0; i < 1000005; i++)  
            {  
                if (year[i]>=y)  
                {  
                    ed = i;  
                    break;  
                }  
            }  
            cout << year[ed + x-1] << endl;  
        }  
        return 0;  
    }  