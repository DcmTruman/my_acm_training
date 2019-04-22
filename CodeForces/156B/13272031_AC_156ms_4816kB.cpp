#include<cstdio>
#define maxn 100005
int n,m,a[maxn],b[maxn],c[maxn],sum,k,d[maxn];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>0)  b[a[i]]++;
        else{
            c[-a[i]]++;
            sum++;
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]+sum-c[i]==m){
            d[i]=1;
            k++;
        }
    }

    for(int i=1;i<=n;i++){
        if(a[i]>0){
            if(d[a[i]]==1&&k==1)    printf("Truth\n");
            else if(d[a[i]]==0) printf("Lie\n");
            else printf("Not defined\n");
        }
        else{
            if(d[-a[i]]==1&&k==1)   printf("Lie\n");
            else if(d[-a[i]]==0)    printf("Truth\n");
            else printf("Not defined\n");
        }
    }
    return 0;
}