#include<stdio.h>
#include<math.h>
main()
{
	long long n;long long i,j,k; 
	while (scanf("%lld",&n)!=EOF)
	{
	  if (n<0) break;
	  if (n==1) {printf("0%%\n");continue;}
	  if (n==2) {printf("50%%\n");continue;}
	  printf("%.0lf%%\n",n*100/4.0);
	}
	return 0;
}

