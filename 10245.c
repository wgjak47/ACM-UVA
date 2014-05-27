#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct point {
	double x,y;
};
struct point data[10001];
int cmp(const void *a,const void *b)
{
	return ((struct point *)b)->x>((struct point *)a)->x?1:-1;
}
main()
{
	int N;
	int i,j,k;
	while (scanf("%d",&N),N!=0)
	{
		double min=100000000;
		for (i=0;i<N;i++)
			scanf("%lf%lf",&data[i].x,&data[i].y);
		qsort(data,N,sizeof(data[0]),cmp);
		for (i=0;i<N;i++)
		for (j=i+1;j<N;j++)
		{
			double dx=(data[i].x-data[j].x);
			if (dx*dx>=min) break;
		else 
		{
			double dy=(data[i].y-data[j].y);
			double temp=dx*dx+dy*dy;
			if (temp<min)
			min=temp;
		}
		}
		if (min<100000000)
		printf("%.4lf\n",sqrt((double)min));
		else printf("INFINITY\n");
	}
	return 0;
}
