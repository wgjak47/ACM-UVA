#include<cstdio>
#include<cstring>
#include<cmath>
main()
{
	long long n;
	while (scanf("%lld",&n)==1)
	{
		while (n>18)
			n=ceil(n/18.0);
		if (n<=9 && n>=2)
			printf("Stan wins.\n");
		else printf("Ollie wins.\n");
	}	
	return 0;
}
