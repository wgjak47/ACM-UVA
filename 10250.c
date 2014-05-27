#include<stdio.h>
#include<math.h>
main()
{
	double x1,x2,y1,y2;
	double i,h,j,k;
	double x3,x4,y3,y4;
	double midx,midy;
	while (scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
	{
		midx=(x1+x2)/2;
		midy=(y1+y2)/2;
		i=x1-midx;
		j=y1-midy;
		x3=midx+j;
		y3=midy-i;
		x4=midx-j;
		y4=midy+i;
		printf("%.10lf %.10lf %.10lf %.10lf\n",x3,y3,x4,y4);
	}
	return 0;
}
