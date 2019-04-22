#include<bits/stdc++.h>
using namespace std;
int n, a[100010];
bool jug() {
    if(n%2) return false;
    int c[3] = {0, 0, 0};
    for(int i=n;i;i--) {
        c[ a[i] ]++;
        if(c[2] > c[1]) return false;
    }
    return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    a[1] = 2;
    while(T--)
    {
        scanf("%d",&n);
        for(int i=2;i<=n;i++)
            scanf("%d",&a[i]);
        printf("%s\n", jug()?"Yes":"No");
    }
}