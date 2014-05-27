#include<stdio.h>
#include<math.h>
main()
{
	long long  a,b,s,m,n;
	double angle,speed,sum;
	const double pi=3.1415926535898;
	while (scanf("%lld%lld%lld%lld%lld",&a,&b,&s,&m,&n))
	{
	   if (a==0 && b==0 && s==0 && m==0 && n==0) break;
	   sum=sqrt(a*m*m*a+n*b*b*n);
	   speed=sum/s;
	   angle=atan(((double)(n*b))/(m*a))*180/pi;
	   printf("%.2lf %.2lf\n",angle,speed);
	}
	return 0;
}

