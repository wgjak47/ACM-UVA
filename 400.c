#include<stdio.h>
#include<string.h>
char s[200][70];
int cmp(const void *a,const void *b)
{
   return strcmp((char *)a,(char * )b);
}
void my_pstring(char *s,int maxline)
{
	int i,l;
	printf("%s",s);
	l=strlen(s);
	for (i=l;i<maxline;i++)
		putchar(' ');
}
main()
{
	int i,j,k,l,m,n,max;
	while (scanf("%d",&n)==1)
	{
		getchar();max=0;
		for (i=0;i<n;i++)
			scanf("%s",s[i]);
		qsort(s,n,sizeof(char)*70,cmp);
		for (i=0;i<n;i++)
           if ((l=strlen(s[i]))>max) max=l;
		k=62/(max+2);
		if (k==0) k++;
		 m=n/k;
		if (n%k!=0) m++;
	for (i=0;i<60;i++) printf("-");putchar('\n');
	for (i=0;i<m;i++)
	{
		for (j=0;j<k-1;j++)
		my_pstring(s[i+j*m],max+2);
		printf("%s",s[i+j*m]);
		putchar('\n');
	}
	memset(s,0,sizeof(s));
	}
	return 0;
}


