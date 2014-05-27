#include<stdio.h>
#include<math.h>
main()
{
	long long a,b,c,n,i,j,k,l,SUM;
	long long s2,r2,s3,r3,s4,r4;
	while(scanf("%lld",&n)!=EOF)
	{
	    SUM=n*(n+1)/2;
		s2=s3=s4=r2=r3=r4=0;
		s2=n*(n+1)*(2*n+1)/6;
		s3=(n+1)*(n+1)*n*n/4;
		s4=n*(n+1)*(2*n+1)*(3*n*n+3*n-1)/30;
		r2=SUM*SUM-s2;
		r3=SUM*SUM*SUM-s3;
		r4=SUM*SUM*SUM*SUM-s4;
        printf("%lld %lld %lld %lld %lld %lld\n",s2,r2,s3,r3,s4,r4);
	}
	return 0;
}

