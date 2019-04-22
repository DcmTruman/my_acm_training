#include <cstdio>
#include <algorithm>
using namespace std;

 long long t, a, b, c, d, x[100020], *p=x;

void run(){
int n;
while(~scanf("%d",&n))
{
    //int n;
	p = x;
    //scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%lld", p+i);
    }
    if (n <= 1) {
        printf("%lld\n", n ? p[0] : 0);
        continue;
    }

    sort(p, p+n);
    t = 0;
    a = p[0], b = p[1];
    p += 2;
    n -= 2;

    while(n >= 2){
        c = p[n-2], d = p[n-1];
        n -= 2;
        /*
        b+a+d+b: ab, a, cd, b
        d+a+c+a: ad, a, ac, a
        */
        t += min(b+a+d+b, d+a+c+a);
    }

    t += n ? p[0]+a+b : b;

    printf("%lld\n", t);
}
}

int main(){
    run();
    return 0;
}

