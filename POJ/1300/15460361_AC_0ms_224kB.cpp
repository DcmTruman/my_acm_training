#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
#include<string>
#define clr(x,b) memset(x,(b),sizeof(x))

using namespace std;

int m,n,du[20] ;
string s;
char s1[1000] ;
int main()
{
    while(cin >>s)
    {
        if(s == "ENDOFINPUT")
            break ;
        cin >> m>> n ;
        getchar() ;
        int cnt = 0;
        clr(du,0);
        for(int i = 0 ; i < n ; i++)
        {
            gets(s1) ;
            int len = strlen(s1) ;
            for(int j = 0 ; j < len ; j++)
            {
                if(s1[j] != ' ')
                {
                    int temp = s1[j]-'0' ;
                    cnt ++ ;
                    du[i] ++ ;
                    du[temp] ++ ;
                }
            }
        }
        cin >> s ;
        int odd = 0 ,even = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(du[i] % 2) odd ++ ;
            else even ++ ;
        }
        if(odd == 0 && m == 0)
            cout<< "YES "<< cnt <<endl ;
        else if(odd == 2 && m != 0)
            cout << "YES "<<cnt <<endl ;
        else cout<<"NO"<<endl ;
    }
    return 0 ;
}