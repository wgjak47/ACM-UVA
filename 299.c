#include<stdio.h>
long long swaper(long long a[],long long m)
{
	long long i,j,k,reg=0;
	for (i=0;i<m;i++)
	for (j=0;j<m-1-i;j++)
	{
		if (a[j]>a[j+1])
		{
		   k=a[j];
		   a[j]=a[j+1];
		   a[j+1]=k;
		   reg++;
		}
	}
	
	return reg;
}

long long  a[100000];
main()
{
	long long  n,m,i,j,k;
	scanf("%lld",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%lld",&m);
		for (j=0;j<m;j++)
			scanf("%lld",&a[j]);
		k=swaper(a,m);
		printf("Optimal train swapping takes %lld swaps.\n",k);
	}
	return 0;
}
