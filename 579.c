#include<stdio.h>
#include<math.h>
main()
{
    int i,j,k,l,m,n;
	double x,y,z;
	while(scanf("%d:%d",&i,&j)==2)
	{
		if (i==0 && j==0) break;
		z=i*30+j/2.0-6*j;
		z=fabs(z);
		if (z>180) z=360-z;
		printf("%.3lf\n",z);
	}
	return 0;
}
