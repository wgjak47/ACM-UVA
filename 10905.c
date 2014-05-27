#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char num[55][300];
int cmp(const void *a,const void *b)
{
	char x[200];
	char y[200];
	strcpy(x,a);
	strcpy(y,b);
	strcat(x,b);
	strcat(y,a);
	return strcmp(y,x);
}
main()
{
	int N;
	int i,j,k;
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		getchar();
		for (i=0;i<N;i++)
		scanf("%s",num[i]);
		qsort(num,N,sizeof(num[0]),cmp);
	    for (i=0;i<N;i++)
			printf("%s",num[i]);
		putchar('\n');
	}
	return 0;
}
