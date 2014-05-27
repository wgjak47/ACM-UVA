#include<cstdio>
#include<cstring>
long long a,b,c;
main()
{
	while (scanf("%lld%lld%lld",&a,&b,&c),a && b && c)
	{
		if (a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
			printf("right\n");
		else printf("wrong\n");
	}
	return 0;
}
