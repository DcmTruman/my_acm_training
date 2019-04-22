#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 2000005;
struct Node
{
    Node *fail;
    Node *next[27];
    int id,cnt;
    Node()
    {
        fail = NULL;
        id = 0;
        cnt = 0;
        memset(next,NULL,sizeof(next));
    }
};
char T[1005][55];
char str[N];
int _cnt[1005];
void buildTrie(char *str,Node *root,int id)
{
    Node *p = root,*q;
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        int idx = str[i]-'A';
        if(p->next[idx]==NULL) p->next[idx]=new Node();
        p = p->next[idx];
    }
    p->id = id;
}
void build_AC_automation(Node *root)
{
    queue<Node*> q;
    root->fail = NULL;
    q.push(root);
    while(!q.empty())
    {
        Node *p = NULL;
        Node *temp = q.front();
        q.pop();
        for(int i=0; i<27; i++)
        {
            if(temp->next[i]!=NULL)
            {
                if(temp==root) temp->next[i]->fail=root;
                else
                {
                    p=temp->fail;
                    while(p!=NULL)
                    {
                        if(p->next[i]!=NULL)
                        {
                            temp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL) temp->next[i]->fail=root;
                }
                q.push(temp->next[i]);
            }
        }
    }
}
void query(char *str,Node *root)
{
    int len = strlen(str);
    Node *p = root;
    for(int i=0; i<len; i++)
    {
        if(str[i]<'A'||str[i]>'Z') str[i]='Z'+1;
        int idx = str[i]-'A';
        while(p->next[idx]==NULL&&p!=root) p = p->fail;
        p = p->next[idx];
        p = (p==NULL)?root:p;
        Node * temp = p;
        while(temp!=root)
        {
            if(temp->id!=0)
            {
                temp->cnt++;
                _cnt[temp->id] = temp->cnt;
            }
            temp = temp->fail;
        }
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        Node *root = new Node();
        memset(_cnt,0,sizeof(_cnt));
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%s",T[i]);
            buildTrie(T[i],root,i);
        }
        getchar();
        build_AC_automation(root);
        gets(str);
        query(str,root);
        for(int i=1; i<=n; i++)
        {
            if(_cnt[i])
            {
                printf("%s: %d\n",T[i],_cnt[i]);
            }
        }
    }
}