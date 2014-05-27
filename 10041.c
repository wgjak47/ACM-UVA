#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
main()
{
	int i,j,k;
	int total;
	int s[600];
	int vis[30101];
	scanf("%d",&total);
	while (total--)
	{
		int N;
		scanf("%d",&N);
		for (i=1;i<=N;i++)
		{
			scanf("%d",&s[i]);
		}
		qsort(s+1,N,sizeof(int),cmp);
		int sum=0;
		if (N%2==0)
		{
			for (i=1;i<=N/2;i++)
				sum+=abs(s[N-i+1]-s[i]);
		}
		else 
		{
			int mid=s[(N+1)/2];
			for (i=1;i<=N;i++)
				sum+=abs(s[i]-mid);
		}
		printf("%d\n",sum);
	}
}
