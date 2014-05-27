#include<stdio.h>
#include<string.h>
#include<math.h>
struct fuck
{
	int num;
	double sum;
};
struct fuck t[1020];
int cmp(const void *a,const void *b)
{
	if (fabs(((struct fuck *)a)->sum-((struct fuck *)b)->sum)<=1e-12)
		return ((struct fuck *)a)->num-((struct fuck *)b)->num;
	else return ((struct fuck *)a)->sum>((struct fuck *)b)->sum;
}
main()
{
	int N,m,i,j;
	int time,fine;
	scanf("%d",&N);
	while (N--)
	{
		scanf("%d",&m);
		for (i=0;i<m;i++)
		{
			scanf("%d%d",&time,&fine);
			t[i].num=i+1;
			t[i].sum=time*1.0/(fine*1.0);
		}
		qsort(t,m,sizeof(struct fuck),cmp);
		for (i=0;i<m;i++)
		{
			printf("%d",t[i].num);
			if (i!=m-1) putchar(' ');
		}
		putchar('\n');
		if (N) putchar('\n');
	}
	return 0;
}
