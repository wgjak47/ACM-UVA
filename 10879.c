#include<stdio.h>
#include<math.h>
main()
{
	long long i,b,c,d,e,f,reg;
	long long a[4];
	scanf("%lld",&e);
	for (i=0;i<e;i++)
	{
		reg=0;
		scanf("%lld",&d);
		for (b=2;b<d&&reg<2;b++)
		{
			if (d%b==0)
			{
				reg++;
				if (reg==1) c=0;else c=2;
				a[0+c]=b;
				a[1+c]=d/b;
			}
		}
		printf("Case #%lld: %lld = %lld * %lld = %lld * %lld\n",i+1,d,a[0],a[1],a[2],a[3]);
	}
	return 0;
}
				



