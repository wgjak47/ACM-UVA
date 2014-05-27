#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data
{
	int W,I,num;
};
struct data in[1200];
int N;
int cmp(const void *a,const void *b)
{
	return ((struct data *)a)->W-((struct data *)b)->W;
}
int total[1200];
int f[1200];
main()
{
	N=0;
	memset(f,-1,sizeof(f));
	while (scanf("%d%d",&in[N].W,&in[N].I)!=EOF) in[N].num=N++;
	qsort(in,N,sizeof(struct data),cmp);
	int i,j;
	memset(total,0,sizeof(total));
	int result=0;
	for (i=N-2;i>=0;i--)
	{
		int	max=0;
		int mj=-1;
		for (j=i+1;j<N;j++)
			if (in[i].W<in[j].W && in[i].I>in[j].I && max<total[j]+1)
			{
				max=total[j]+1;mj=j;
			}
		total[i]=max;f[i]=mj;
		if (total[i]>total[result]) 
			result=i;
	}
	printf("%d\n",total[result]+1);
	for (i=result;i!=-1;i=f[i]) printf("%d\n",in[i].num+1);
	return 0;
}
