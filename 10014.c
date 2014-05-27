#include<stdio.h>
#include<math.h>
int max;
double as,ae;
double c[4000];
main()
{ 
	int i,j,k;double sum,calculations;
	scanf("%d",&k);
	for (i=0;i<k;i++)
 	{
		sum=0;
		scanf("%d",&max);
		scanf("%lf",&as);
		scanf("%lf",&ae);
		calculations=max*as+ae;
		for (j=1;j<=max;j++)
		{
		    scanf("%lf",&c[j]);
            sum+=c[j];
			calculations-=2*sum;
		}
		printf("%.2lf\n",calculations/(max+1));
		if (i!=k-1) putchar('\n');
	}
	return 0;
}

