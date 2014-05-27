#include<stdio.h>
#include<math.h>
#define e 2.718281828459
double p,q,r,s,t,u;
double cal(double x)
{
	return p/pow(e,x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
void find(double min,double max)
{
	if (max-min<1e-4)
	int mid=(min+max)/2;
	if (cal(mid)==0) 
	{
		printf("%lf\n",mid);
		return  ;
	}
	if (cal(mid)*cal(min)<0) 
		find(min,mid);
	if (cal(mid)*cal(max)<0)
		find(mid,max);
}
main()
{
	while (scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!=EOF)
	{
		double left=cal(1.0);
		double right=cal(0);
		if (left*right>0) printf("No solution\n");
		else if (left==0) printf("1\n");
		else if (right==0) printf("0\n");
		else find(0,1.0);
	}
}
