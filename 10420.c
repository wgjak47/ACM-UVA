#include<stdio.h>
#include<string.h>
char s[2010][100]={0};
int cmp(const void *a,const void *b)
{
	return strcmp(a,b);
}
int my_strcmp(char *s,char *sc)
{
	int i=0,j=0;
	while (s[i++]==sc[j++])
	if  (sc[j-1]==' ') return 1;
	return 0;
}
void my_printf(char *s)
{
	int i=0;
	while (s[i++]!=' ')
	putchar(s[i-1]);
}
main()
{
	int i,j,k,l,m,n,reg=1;
	scanf("%d",&n);
		getchar();
	for (i=0;i<n;i++)
	fgets(s[i],sizeof(s[i]),stdin);
	qsort(s,n,sizeof(char) *100,cmp);
    for (i=0;i<n;i++)
    if (strcmp(s[i],s[i+1]))
	{
	if (my_strcmp(s[i],s[i+1]))
	reg++;
	else 
	{
	my_printf(s[i]);
	putchar(' ');
	printf("%d\n",reg);
	reg=1;
	}
	}
	return 0;
}


