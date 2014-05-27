#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char s[100001][100];
char convert(char s)
{
	switch(s)
	{
		case 'A':case 'B':case 'C':return '2';
		case 'E':case 'F':case 'D':return '3';
		case 'H':case 'I':case 'G':return '4';
		case 'K':case 'J':case 'L':return '5';
		case 'O':case 'N':case 'M':return '6';
		case 'P':case 'R':case 'S':return '7';
		case 'U':case 'T':case 'V':return '8';
		case 'W':case 'X':case 'Y':return '9';
		default: return s;
	}
}
int cmp(const void *a,const void *b)
{
	return strcmp((char *)a,(char *)b);
}
void my_puts(int i)
{
	int j;
	for (j=0;j<3;j++)
		putchar(s[i][j]);
        putchar('-');
	for (j=3;j<7;j++)
		putchar(s[i][j]);
}	
main()
{
	int i,j,k,l,m,n,reg=0,re,w;
	int flag;
        scanf("%d",&n);
	for (w=1;w<=n;w++)
	{
		flag=0;
		if (w!=1) putchar ('\n');
		scanf("%d",&m);
		getchar();
		for (i=0;i<m;i++)
		{
		    fgets(s[i],sizeof(s[i]),stdin);
			l=strlen(s[i]);
			k=0;
			for (j=0;j<=l;j++)
			if (isdigit(s[i][j]) || isalpha(s[i][j]) || s[i][j]=='\0')
			s[i][k++]=s[i][j];
			strlen(s[i]);
			for (j=0;j<=l;j++)
			s[i][j]=convert(s[i][j]);
		}
	qsort(s,m,sizeof(char)*100,cmp);
	re=1;

	for (i=0;i<m;i++)
    {
		if (!strcmp(s[i],s[i+1])) re++;
		else
		{
			if (re>1)
			{
			flag=1;
			my_puts(i);
			printf(" %d",re);
            putchar('\n');
			re=1;
			}
		}
	}
	if (flag==0)  printf("No duplicates.\n");
	memset(s,'a',sizeof(s));
	}
    return 0;
}




