#include<stdio.h>
#include<math.h>

struct n{
    double x,y,v;
}Node[1020];
int main()
{
    double a,b;
    int n;
    scanf("%lf %lf",&a,&b);
    scanf("%d",&n);
    for(int i = 0; i<n;i++){
        scanf("%lf %lf %lf",&Node[i].x,&Node[i].y,&Node[i].v);
    }
    double ans = 100000000;
    for( int i=0;i<n;i++){
        double temp = sqrt((a-Node[i].x)*(a-Node[i].x)+(b-Node[i].y)*(b-Node[i].y))/Node[i].v;
        if(ans-temp>1e-6)ans = temp;
    }
    printf("%.15f",ans);
}