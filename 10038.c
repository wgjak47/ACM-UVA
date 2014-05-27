#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	int a[10000],N;
	int result[3010];
	int i,j,k;
	int jolly;
	while (scanf("%d",&N)!=EOF)
	{
		memset(result,0,sizeof(result));
		jolly=1;
		for (i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
			if (i>0)
			result[abs(a[i]-a[i-1])]=1;
		}
		for (i=1;i<N;i++)
			if (!result[i]) 
			{
				jolly=0;
				break;
			}
		if (jolly) printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}
