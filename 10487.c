#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int Sum[1000100];
int N,M,k;
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int divide(int D)
{
	int m;
	int b=k,s=0;
	while (b-s>1)
	{
		 m=s+(b-s)/2;
		 if (Sum[m]==D) return D;
		 else if (Sum[m]>D) b=m;
		 else s=m;
	}
	if (abs(Sum[s]-D)>abs(Sum[b]-D))
		return Sum[b];
	else return Sum[s];
}
main()
{
	int sum[1200];
	int i,j,reg=0;
	while (scanf("%d",&N),N!=0)
	{
		for (i=0;i<N;i++)
			scanf("%d",&sum[i]);
		k=0;
		for (i=0;i<N;i++)
		for (j=i+1;j<N;j++)
			Sum[k++]=sum[i]+sum[j];
		qsort(Sum,k,sizeof(int),cmp);
		scanf("%d",&M);
		int Q;
		printf("Case %d:\n",++reg);
		for (j=0;j<M;j++)
		{
			scanf("%d",&Q);
			printf("Closest sum to %d is %d.\n",Q,divide(Q));
		}
	}
	return 0;
}
