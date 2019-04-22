#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f
#define oo 1000000000000000
#define N 102550
#define PI 4*atan(1.0)
#define mod 100000001
#define met(a, b) memset(a, b, sizeof(a))
typedef long long LL;

struct node
{
    int num;
    node *Next[2];
};

void Add(node *head, int num)
{
    node *p = head;
    for(int i=31; i>=0; i--)
    {
        int k = (num>>i)&1;
        if(p->Next[k] == NULL)
        {
            node *q = new node();
            p->Next[k] = q;
        }
        p = p->Next[k];
    }
    p->num = num;
}

int Find(node *head, int num)
{
    node *p = head;
    for(int i=31; i>=0; i--)
    {
        int k = (num>>i)&1;
        if(p->Next[k^1] != NULL)
            p = p->Next[k^1];
        else
            p = p->Next[k];
    }
    return p->num;
}

int main()
{
    int T, t = 1, n, m, num;
    scanf("%d", &T);
    while(T--)
    {
        node *head = new node();

        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &num);
            Add(head, num);
        }

        printf("Case #%d:\n", t++);

        for(int i=1; i<=m; i++)
        {
            scanf("%d", &num);
            int ans = Find(head, num);
            printf("%d\n", ans);
        }
    }
    return 0;
}