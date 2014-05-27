#include<stdio.h>
main ()
{
	int n,i,s,k;
	while (scanf("%d",&n),n!=0)
	{	
		if (n<=100) s=91;
		else s=n-10;
		printf("f91(%d) = %d\n",n,s);
	}
    return 0;
}
