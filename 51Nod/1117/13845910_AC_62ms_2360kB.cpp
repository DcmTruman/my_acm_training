#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int>>Q;
    int n,k;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>k;
        Q.push(k);
    }
    int ans = 0;

    while(Q.size()>1)
    {
        
        int x1 = Q.top();
        Q.pop();
        int x2 = Q.top();
        Q.pop();
        ans += x1+x2;
        Q.push(x1+x2);
    }
    cout<<ans<<endl;
}