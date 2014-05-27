#include<stdio.h>
#include<math.h>
long long factor[500002]={0};
int primer(long long j)
{
	int i,temp;
	temp=(int)sqrt(j)+1;
	for (i=2;i<=temp;i++)
		if (j%i==0) return 0;
	return 1;
}
fuck_factor()
{
	int i,j=2,k=0;
	for (i=1;i<=80000;i++)
	{
		while (!primer(j)) j++;
		factor[i]=j;
		j++;
	}
}	
main()
{
	long long i,j,l,prime;
	fuck_factor();
	factor[0]=2;
	while (scanf("%lld",&prime)!=EOF)
	{
		if (prime<0) break;
			for (i=0;i<=80000;i++)
			while (prime%factor[i]==0)
			{
				printf("    %lld\n",factor[i]);
				prime/=factor[i];
			}
		if (prime!=1) printf("    %lld\n",prime);
		putchar('\n');
	}
	return 0;
}
