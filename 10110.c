#include<stdio.h>
#include<math.h>
#define sq floor(sqrt(n)+0.5)
main()
{
	long long n;
    long long k;
    while (scanf("%lld",&n)!=EOF)
	{
		if (n==0) break;
		k=sq;
		if (k*k==n)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
