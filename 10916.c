#include<stdio.h>
#include<math.h>
int er(int x)
{
	int i,sum=1;
	for (i=1;i<=x;i++)
      sum*=2;
	return sum;
}
main()
{
	long long k;
	int n;
	long long l=0;
	int year,m;
	double x=0,p;
	while(scanf("%d",&year))
	{
		l=0;x=0;
		if (year==0) break;
		year-=1960;
		m=year/10;
		k=4*er(m);
    while (x<k*log(2))
	{
     l++;
     x+=log(l);
	}
	printf("%lld\n",l-1);
	}
	return 0;
}




