#include<stdio.h>
#include<string.h>
struct time
{
	int start,end;
	int nap;	
};
int cmp1(const void *a,const void *b)
{
	return ((struct time *)a)->start-((struct time *)b)->start;
}
int cmp2(const void *a,const void *b)
{
	if (((struct time *)a)->nap-((struct time *)b)->nap)
	return 	((struct time *)b)->nap-((struct time *)a)->nap;
		else  
	return ((struct time *)a)->end-((struct time *)b)->end;
}
struct time professor[111];
main()
{
	int N;
	int i,j,k,l;
	int a,b,c,d;
	char temp[300];
	int reg=0;
	while (scanf("%d",&N)==1)
	{
		getchar();
		for (i=1;i<=N;i++)
		{
			scanf("%d:%d %d:%d",&a,&b,&c,&d);
			professor[i].start=a*60+b;
			professor[i].end=c*60+d;
			gets(temp);
		}
		professor[N+1].start=18*60;
		professor[N+1].end=18*60;
		professor[0].end=600;
		professor[0].start=600;
		qsort(professor+1,N,sizeof(struct time),cmp1);
		for (i=0;i<=N;i++)
			professor[i].nap=professor[i+1].start-professor[i].end;
		qsort(professor,N+1,sizeof(struct time),cmp2);
		int th=professor[0].end/60;int tm=professor[0].end%60;
		int nh=professor[0].nap/60;int nm=professor[0].nap%60;
		if (nh==0)
			printf("Day #%d: the longest nap starts at %d:%.2d and will last for %d minutes.\n",++reg,th,tm,nm);
		else printf("Day #%d: the longest nap starts at %d:%.2d and will last for %d hours and %d minutes.\n",++reg,th,tm,nh,nm);
	}
		return 0;
}
