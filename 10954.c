#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int data[5011];
int queue[115100];
int N;
int result;
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
void solve()
{
	int front=1;
	int tail=0;
	int k=2;
	int i,j,l,m;
	queue[tail]=data[1]+data[0];
	result=queue[tail];
	int sum[4];
	while (front>tail)
	{
		if (k<N-1) sum[0]=data[k+1]+data[k];
		else sum[0]=-1;
		if (k<N) sum[1]=data[k]+queue[tail];
		else sum[1]=-1;
		if (front-tail>1) sum[2]=queue[tail]+queue[tail+1];
		else sum[2]=-1;
		int min=0;
		while (sum[min]==-1 && min<=2) min++;
		for (i=min;i<3;i++)
			if (sum[min]>sum[i] && sum[i]>0) min=i;
		switch (min)
		{
			case 0:
				k+=2;
				queue[front]=sum[min];
				result+=sum[min];
				front++;
				break;
			case 1:
				k++;
				queue[front]=sum[min];
				front++;
				tail++;
				result+=sum[min];
				break;
			case 2:
				queue[front]=sum[min];
				front++;
				tail+=2;
				result+=sum[min];
				break;
			case 3:tail++;break;
		}
	}
	return ;
}
main()
{
	int i,j,k,l;
	while (scanf("%d",&N),N!=0)
	{
		for (i=0;i<N;i++)
			scanf("%d",&data[i]);
		qsort(data,N,sizeof(int),cmp);
		solve();
		printf("%d\n",result);			
	}
	return 0;
}
