#include<stdio.h>
#include<math.h>
main()
{
	int a,b;
	while (scanf("%d%d",&a,&b))
	{
		if (a==0 && b==0) break;
		printf("%d\n",(int)(floor(sqrt(b)))-(int)ceil(sqrt(a))+1);
	}
	return 0;
}
