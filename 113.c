#include<stdio.h>
#include<math.h>
main()
{
	long long x;
	long long m;
	double y;
	while (scanf("%lld%lf",&x,&y)==2)
	{
	y=log10(y)/x;
	y=pow(10,y);
	printf("%.0lf\n",y);
	}
	return 0;
}
