# include <iostream>
# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <math.h>
# include <queue>
# include <string>
# include <vector>
# include <set>
# include <map>
# define INF 0x3f3f3f3f
# define clr0(x) memset(x,0,sizeof(x))
# define clr1(x) memset(x,INF,sizeof(x))
# define rep(i,a) for(int i = 0;i<(a);i++)
# define repf(i,a,b) for(int i = (a);i<=(b);i++)
# define repu(i,a,b) for(int i = (a);i<(b);i++)
# define repd(i,a,b) for(int i = (a);i>=(b);i--)
# define lowbit x&(-x)
# define ww(a) while(a)
# define sc(x) scanf("%d",&(x))
# define pc(x) printf("%d\n",(x));
# define lson(x) (x)<<1
# define rson(x) (x)<<1|1
# define ll long long
# define fuckio ios::sync_with_stdio(false);
# define fuck cout<<"fuck:"<<__LINE__<<endl;
# define maxn 10020


using namespace std;

const int mod = 1e4+7;
const int max_tot = 50020;

//
//struct KMP{
//	int nexta[maxn];
//	void init(){
//		clr0(nexta);
//	}
//	void getnext(char *s){
//		clr0(nexta);
//		nexta[0] = -1;
//		int i = -1;int j = 0;
//		int n = strlen(s);
//		ww(j<n){
//			if(i == -1||s[i] == s[j]){
//				nexta[j+1] = i+1;
//				i++;j++;
//			}else {
//				i = nexta[i];
//			}
//		}
//	}
//	int kmp(char *s,char *t){
//		int n = strlen(s);
//		int m = strlen(t);
//		int res = -1;
//		int i = 0,j = 0;
//		ww(i<n&&j<m){
//			if(j == -1||s[i] == t[j]){
//				i++;j++;
//			}else{
//				j = nexta[j];
//			}
//		}
//		if(j == m)res = i-m;
//		return res;
//	}
//};
//
//struct EXKMP{
//	int nexta[maxn];
//	int extnd[maxn];
//	void init(){
//		clr0(nexta);
//		clr0(extnd);
//	}
//	
//	void getnxt(char *T)
//	{
//		init();
//	    int len=strlen(T),a=0;
//	    nexta[0]=len;
//	    while(a<len-1 && T[a]==T[a+1]) a++;
//	    nexta[1]=a;
//	    a=1;
//	    repf(k,2,len-1)
//	    {
//	        int p=a+nexta[a]-1,L=nexta[k-a];
//	        if( (k-1)+L >= p)
//	        {
//	            int j = (p-k+1)>0 ? (p-k+1) : 0;
//	            ww(k+j<len && T[k+j]==T[j]) j++;
//	            nexta[k]=j;
//	            a=k;
//	        }
//	        else
//	            nexta[k]=L;
//	    }
//	}
//	void getexnd(char *S,char *T)
//	{
//	    getnxt(T);
//	    int slen=strlen(S),tlen=strlen(T),a=0;
//	    int MinLen = slen < tlen ? slen : tlen;
//	    while(a<MinLen && S[a]==T[a]) a++;
//	    extnd[0]=a;
//	    a=0;
//	    for(int k=1; k<slen; k++)
//	    {
//	        int p=a+extnd[a]-1, L=nexta[k-a];
//	        if( (k-1)+L >= p)
//	        {
//	            int j= (p-k+1) > 0 ? (p-k+1) : 0;
//	            while(k+j<slen && j<tlen && S[k+j]==T[j]) j++;
//	            extnd[k]=j;
//	            a=k;
//	        }
//	        else
//	            extnd[k]=L;
//	    }
//	}
//};
vector<int>v;
int ans[1020];
struct Aho{

    int size = 1;
    queue<int>q;

    struct _node{
        int nxt[27];
        int cnt,fail,id;
    }node[max_tot];

    void init(){
        size = 1;
        while(!q.empty())q.pop();
        rep(i,max_tot){
            clr0(node[i].nxt);
            //rep(j,27)node[i].nxt[j] = 0;
            node[i].cnt = node[i].fail =node[i].id= 0;
        }
    }

    void ins(char *s,int x){
        int n = strlen(s);
        int now = 0;
        rep(i,n){
            int c = s[i]-'A';
            //if(c<0||c>25)c = 26;
            if(!node[now].nxt[c])node[now].nxt[c] = size++;
            now = node[now].nxt[c];
        }
        node[now].cnt++;
        node[now].id = x;
    }

    void build(){
        node[0].fail = -1;
        q.push(0);
        ww(!q.empty()){
            int u = q.front();
            q.pop();
            rep(i,27){
                if(node[u].nxt[i]){
                    if(u == 0)node[node[u].nxt[i]].fail = 0;
                    else{
                        int v = node[u].fail;
                        ww(v!=-1){
                            if(node[v].nxt[i]){
                                node[node[u].nxt[i]].fail = node[v].nxt[i];
                                break;
                            }else{
                                v = node[v].fail;
                            }
                        }
                        if(v == -1)node[node[u].nxt[i]].fail = 0;
                    }
                    q.push(node[u].nxt[i]);
                }
            }
        }
    }

    int fid(char *s){
        int n = strlen(s);
        int res = 0;
        int now = 0;
        rep(i,n){
            if(s[i]<'A'||s[i]>'Z')s[i]= 'Z'+1;
            int c = s[i]-'A';
            if(node[now].nxt[c]){
                now = node[now].nxt[c];
            }else{
                int p = node[now].fail;
                ww(p!=-1&&node[p].nxt[c] == 0)p = node[p].fail;
                if(p == -1)now = 0;
                else now = node[p].nxt[c];
            }
            if(node[now].cnt){
                res++;
                ans[node[now].id]++;
            }
        }
        return res;
    }

}aho;

char virus[1020][100];
char s[2000020];
int n,m;
int main()
{
	ww(sc(n)!=EOF){
		clr0(ans);
		aho.init();
		repf(i,1,n){
			scanf("%s",virus[i]);
			aho.ins(virus[i],i);
		}
		aho.build();
		scanf("%s",s);
		if(aho.fid(s)){
			repf(i,1,n){
				if(ans[i]){
					printf("%s: %d\n",virus[i],ans[i]);
				}
			}
		}
	}
}

