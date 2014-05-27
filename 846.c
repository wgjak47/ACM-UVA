#include<stdio.h>
#include<stdlib.h>
main()
{
	long long s,i,j,k,sum,n,m,all;
	scanf("%lld",&all);
	for (s=0;s<all;s++)
	{
		k=0;
		scanf("%lld%lld",&m,&n);
		sum=abs(m-n);
		i=1;j=0;
		while (sum>0)
		{
			sum-=i;
			k++;
			if (j) i++;
			j=!j;
		}
    printf("%lld\n",k);
	}
	return 0;
}

