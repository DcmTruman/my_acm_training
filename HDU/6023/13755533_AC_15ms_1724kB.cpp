#include<iostream>
#include<string>
#include<string.h>

using namespace std;
int wtime[15];
bool isAC[15];
int cal(string ss)
{
    return 10*60*(ss[0]-'0')+60*(ss[1]-'0')+10*(ss[3]-'0')+(ss[4]-'0');
}
int main()
{
    int T;
    int n,m;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        int num;
        string st;
        string re;
        int ans = 0;
        int cnt = 0;
        memset(wtime,0,sizeof(wtime));
        memset(isAC,0,sizeof(isAC));

        for(int i = 0;i<m;i++)
        {
            cin>>num;
            num -= 1000;
            cin>>st>>re;
            if(re == "AC"&&!isAC[num])
            {
                isAC[num] = true;
                ans += wtime[num]*20+cal(st);                
                cnt++;
            }
            else if(re!="AC")
            {
               wtime[num]++; 
            }
        }
        
        cout<<cnt<<" "<<ans<<endl;
    }
}