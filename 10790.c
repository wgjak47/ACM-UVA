#include<stdio.h>
#include<math.h>
main()
{
	unsigned long long a,b,c,d,reg=0;
	while (scanf("%llu%llu",&a,&b)==2)
	{
		if (a==b && b==0) break;
		reg++;
		c=a*(a-1)/2;
		d=b*(b-1)/2;
		printf("Case %llu: %llu\n",reg,c*d);
	}
	return 0;
}
