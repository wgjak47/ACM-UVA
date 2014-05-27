#include<stdio.h>
#include<math.h>
double judge(double x1,double y1,double z1,double x2,double y2,double z2)
{
   return  sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}
main()
{ 
	long long a[12]={0};
	double  x[6000],y[6000],z[6000];
	long long i=0,j,k,l,m,n,min;
	long long d,e,r;
	while(scanf("%lld%lld%lld",&d,&e,&r))
	{	
		if (d==0  &&  e==0  && r==0) break;
		x[i]=d;
		y[i]=e;
		z[i]=r;
		i++;
	}
	n=i-1;
	min=11;
	for (i=0;i<=n;i++)
 	{
	for (j=0;j<=n;j++)
	if (i!=j)
     {
		k=(long long) judge(x[i],y[i],z[i],x[j],y[j],z[j]);
		if (k<11)
		if (k<min) min=k;
	}
	a[min]++;
	min=11;
	}
    for (i=0;i<=9;i++)
		printf("%4lld",a[i]);
	putchar('\n');
	return 0;
}



