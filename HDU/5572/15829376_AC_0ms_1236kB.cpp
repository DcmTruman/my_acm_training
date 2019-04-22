#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const double eps=1e-8;
int main()
{
	int T;
	double dx,dy,R,vx,vy;
	double Ax,Ay,Bx,By,Mx,My,Px,Py;
	double a,b,c,delta,t1,t2,t,len;
	bool flag;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		scanf("%lf %lf %lf",&dx,&dy,&R);
		scanf("%lf %lf %lf %lf",&Ax,&Ay,&vx,&vy);
		scanf("%lf %lf",&Bx,&By);
		Bx-=dx; By-=dy; Ax-=dx; Ay-=dy;
		len=0.01*vx*vx+0.01*vy*vy;
		vx/=len; vy/=len;
		a=1.0*vx*vx+1.0*vy*vy;
		b=2.0*(Ax*vx+Ay*vy);
		c=1.0*Ax*Ax+1.0*Ay*Ay-1.0*R*R;
		delta=b*b-4.0*a*c;
		t=-1.0;
		if(delta>eps){
			t1=(-b-sqrt(delta))/(2.0*a);
			t2=(-b+sqrt(delta))/(2.0*a);
			if(t1>eps) t=t1;
			else if(t2>eps) t=t2;
			else t=-1.0;
		}
		
		flag=false;
		if(fabs((By-Ay)*vx-(Bx-Ax)*vy)<eps){
			t1=-1.0;
			if(fabs(vx)>eps){
				t1=(Bx-Ax)/vx;
			}else if(fabs(vy)>eps){
				t1=(By-Ay)/vy;
			}
			if(t1>eps && (t<eps || t1<t+eps) ) flag=true;
		}
		
		printf("Case #%d: ",cas);
		if(flag==true){
			printf("Yes\n"); continue;
		}
		
		//printf("debug %.2f\n",t);
		if(t>eps){
			Mx=Ax+vx*t; My=Ay+vy*t;
			Px=Bx-Mx; Py=By-My;
			a=Mx/sqrt(Mx*Mx+My*My);
			b=My/sqrt(Mx*Mx+My*My);
			Bx=Px-2.0*(Px*a+Py*b)*a+Mx;
			By=Py-2.0*(Px*a+Py*b)*b+My;
			//printf("%.2f %.2f %.2f %.2f\n",Mx,My,Bx,By);
		}
		flag=false;
		if(fabs((By-Ay)*vx-(Bx-Ax)*vy)<eps){
			t1=-1.0;
			if(fabs(vx)>eps){
				t1=(Bx-Ax)/vx;
			}else if(fabs(vy)>eps){
				t1=(By-Ay)/vy;
			}
			//printf("%.2f %.2f %.2f\n",vx,vy,t);
			if(t1>t+eps) flag=true;
		}
		if(flag==true){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}

/*

100
0 0 1
2 2 0 1
-1 -1
0 0 1
-1 2 1 -1
1 2
0 0 1
0 4 0 -1
0 8

*/
