#include<stdio.h>
#include<string.h>
int in[200010];
main()
{
	int T;
	int N;
	int i,j,k;
	int reg=1;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		N--;
		for (i=0;i<N;i++)
			scanf("%d",&in[i]);
		int sum=0;
		int max_sum=in[0];
		int start=1,end=1;
		int s=1,t=1;
		for (i=0;i<N;i++)
		{
			sum+=in[i];
			if (sum>max_sum)
			{
				max_sum=sum;
				end=i+2;
				start=t;
			}
			else if(sum==max_sum && end-start<i+2-t)
			{
				end=i+2;
				start=t;
			}
			if (sum<0)
			{
				sum=0;
				t=i+2;
			}
		}
		if (max_sum>=0)
		printf("The nicest part of route %d is between stops %d and %d\n",reg++,start,end);
		else printf("Route %d has no nice parts\n",reg++);
	}
		return 0;
}
