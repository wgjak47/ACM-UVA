#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
main()
{
	int N;
	int a[1200];
	while (scanf("%d",&N)==1)
	{
		int total;
		for (int i=0;i<total;i++)
			scanf("%d",&a[i]);
		qsort(a,total,sizeof(int),cmp);
				
	}
}
