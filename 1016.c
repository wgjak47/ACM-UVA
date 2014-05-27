#include<stdio.h>
#include<math.h>
main()
{
    double x,y;
    int n,p;
    int *m;
    m=&p;
    scanf("%lf",&x);
    y=frexp(x,m);
    printf("%d",p-1);
    return 0;
}
