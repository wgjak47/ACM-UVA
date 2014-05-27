//咬文嚼字，注意0的情况
#include<cstdio>
#include<cmath>
main()
{
	double a,b,c;
	while (scanf("%lf%lf%lf",&a,&b,&c)==3)
	{
		double p=(a+b+c)/2.0;
		double s=sqrt(p*(p-a)*(p-b)*(p-c))/p;
		if (a!=0 && b!=0 && c!=0)
		printf("The radius of the round table is: %.3f\n",s);
		else printf("The radius of the round table is: 0.000\n");
	}
	return 0;
}
