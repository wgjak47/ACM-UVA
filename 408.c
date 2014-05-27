#include<stdio.h>
int gys(int a,int b)
{
	if (b==0) return a;
	if (a>b)
		return gys(b,a%b);
	else return gys(a,b%a);
}


main()
{
	long long a,b,c,d;
	while (scanf("%lld%lld",&a,&b)==2)
	{
		printf("%10lld%10lld    ",a,b);
		if (gys(a,b)==1)
			printf("Good Choice\n\n");
		else 
			printf("Bad Choice\n\n");
	}
	return 0;
}
