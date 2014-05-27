#include<stdio.h>
main()
{
	unsigned long long a;
	while (scanf("%llu",&a)==1)
	{
		printf("%llu\n",((a+1)/2*(a+1)-3)*3);
	}
	return 0;
}
