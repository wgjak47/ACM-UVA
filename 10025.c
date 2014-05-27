#include<stdio.h>
#include<math.h>
main()
{
	long long k,n,i,j,sum,m;
	scanf("%lld",&m);
	for (i=0;i<m;i++)
	{
		if (i) putchar('\n');
		scanf("%lld",&k);
		if (k<0) k=-k;
		if (k==0) { printf("3\n");continue;}
        n=(long long)sqrt(k);
		sum=(n+1)*n/2;
		while  (k>sum) 
		{
			n++;
			sum+=n;
		}
		if (sum==k) printf("%lld\n",n);
		else
		{
		while ((sum-k)%2!=0)
		{
		   n++;
		   sum+=n;
		}
		printf("%lld\n",n);
		}
	}
	return 0;
}
	    	   
