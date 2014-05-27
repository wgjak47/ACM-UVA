#include<stdio.h>
#include<string.h>
char s[1000][2000];
typedef struct 
{
	char name[2000];
	int num;
} shell;
shell md[1000];
shell *m[1000];
void out(int x)
{
	int i;shell *temp=m[x];
	puts(m[x]->name);
	for (i=x;i>0;i--)
		m[i]=m[i-1];
	m[0]=temp;
}
main()
{ 
	int i,j,k,l,total,row,max;
	scanf("%d",&total);
	for (l=1;l<=total;l++)
 	{
		scanf("%d",&row);
		getchar();
		for (j=0;j<row;j++)
		{
		  gets(md[j].name);
		  m[j]=&md[j];
		}
		for (j=0;j<row;j++)
		{
		  gets(s[j]);
		  for (k=0;k<row;k++)
			  if (!strcmp(m[k]->name,s[j]))
			  {
				  m[k]->num=j;
				  break;
			  }
		}
		k=row-1;
		for (i=row-1;i>=0;i--)
			if (m[i]->num==k)
				k--;
			for (i=0;i<row;i++)
			{
			    if (k==m[i]->num)
				{
					out(i);
					k--;
				    i=0;
				}
			}
		putchar('\n');
	}
	return 0;
}
