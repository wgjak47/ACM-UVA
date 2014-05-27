#include<stdio.h>
main()
{
	int a[20];
	long long n,i,j,sum,max,reg=0;
	while (scanf("%lld",&n)==1)
	{
		sum=1;max=0;
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
       for (i=0;i<n;i++)
	   {
	      for (j=i;j<n;j++)
		  {
			  sum*=a[j];
		      if (max<sum) max=sum;
		  }
		  sum=1;
	   }
	   printf("Case #%lld: The maximum product is %lld.\n\n",++reg,max);
	}
return 0;
}


