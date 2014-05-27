#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int p,q,r,s,t,u;
double cal(double x)
{
	return p/exp(x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
double find(double min,double max)
{
	if (max-min<1e-8) {printf("%.4lf\n",min);return ;}
	double mid=min+(max-min)/2;
	if (cal(mid)==0) 
	{
		printf("%.4lf\n",mid);
		return ;
	}
	if (cal(mid)*cal(max)<0) find(mid,max);
	else
	if (cal(min)*cal(mid)<0) find(min,mid);
}
main()
{
	while (scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)==6)
	{
		double left=cal(0),right=cal(1.0);
		if (left*right > 0) printf("No solution\n");
		else if (left==0) printf("0.0000\n");
		else if (right==0) printf("1.0000\n");
		else find(0,1);
	}
	return 0;
}
