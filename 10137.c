#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
	double money[1000];
	int N;
	int i;
	double average;
	double result1,result2;
	int temp;
/*	freopen("in.in","r",stdin);*/
	while(scanf("%d",&N),N!=0)
	{
		average=0;
		result1=0;
		result2=0;
		for (i=0;i<N;i++)
		{
			scanf("%lf",&money[i]);
			average+=money[i];
		}
		average=average/N+0.005;
		temp=(int) (average*100);
		average=temp/100.0;
		for (i=0;i<N;i++)
			if (average<money[i])
				result1+=money[i]-average;
			else result2+=average-money[i];
		if (result1<result2)
		printf("$%.2lf\n",result1);
		else printf("$%.2lf\n",result2);
	}
	return 0;
}
